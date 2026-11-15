#!/usr/bin/env bash
set -euo pipefail

# Imports ONLY tracked files at HEAD from each private module repository.
# It does not modify or push to the original repositories or to GitHub.

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SCHEME="${1:---ssh}"
case "$SCHEME" in
  --ssh|--https) ;;
  *) echo "Usage: $0 [--ssh|--https]" >&2; exit 2 ;;
esac
for tool in git tar mktemp; do
  command -v "$tool" >/dev/null 2>&1 || { echo "Missing: $tool" >&2; exit 1; }
done

TMPDIR_IMPORT="$(mktemp -d)"
trap 'rm -rf "$TMPDIR_IMPORT"' EXIT

# Download every source before importing anything, to reduce partial imports.
for n in 00 01 02 03 04 05 06 07 08 09; do
  mod="CPP$n"
  if [ -d "$ROOT/$mod/ex00" ]; then
    echo "ERROR: $ROOT/$mod/ex00 already exists; refusing to overwrite any source." >&2
    exit 1
  fi
  if [ "$SCHEME" = "--https" ]; then
    url="https://github.com/doooriian/$mod.git"
  else
    url="git@github.com:doooriian/$mod.git"
  fi
  echo "Fetching $mod from its private repository..."
  git clone --quiet --depth 1 "$url" "$TMPDIR_IMPORT/$mod" || {
    echo "Cannot clone $url. Check your GitHub authentication and repository access." >&2
    exit 1
  }
done

# git archive exports tracked source at HEAD without .git directories or local build artifacts.
for n in 00 01 02 03 04 05 06 07 08 09; do
  mod="CPP$n"
  mkdir -p "$ROOT/$mod"
  echo "Importing tracked source of $mod..."
  git -C "$TMPDIR_IMPORT/$mod" archive --format=tar HEAD | tar -xf - -C "$ROOT/$mod"
done

echo
echo "Imported CPP00 through CPP09 successfully."
echo "Next: inspect the files, run ./scripts/check-builds.sh, and follow PUBLISHING.md."
echo "Nothing has been published to GitHub."
