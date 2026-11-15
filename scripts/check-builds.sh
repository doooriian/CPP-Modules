#!/usr/bin/env bash
set -uo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
command -v make >/dev/null 2>&1 || { echo "Missing make" >&2; exit 1; }
found=0; passed=0; failed=0
for module in "$ROOT"/CPP{00,01,02,03,04,05,06,07,08,09}; do
  [ -d "$module" ] || continue
  for exercise in "$module"/ex[0-9][0-9]; do
    [ -f "$exercise/Makefile" ] || continue
    found=$((found + 1))
    rel="${exercise#"$ROOT"/}"
    printf '%-20s' "$rel"
    if make -s -C "$exercise" > /dev/null 2> /tmp/cpp-modules-build-check-$$.log; then
      echo "PASS (build)"
      passed=$((passed+1))
    else
      echo "FAIL (build)"
      sed -n '1,8p' /tmp/cpp-modules-build-check-$$.log | sed 's/^/    /'
      failed=$((failed+1))
    fi
    make -s -C "$exercise" fclean >/dev/null 2>&1 || true
  done
done
rm -f /tmp/cpp-modules-build-check-$$.log
printf '\nBuild checks: %d passed, %d failed, %d attempted.\n' "$passed" "$failed" "$found"
if [ "$found" -eq 0 ]; then
  echo 'No exercise Makefiles found under CPP00–CPP09.'
  exit 2
fi
[ "$failed" -eq 0 ]
