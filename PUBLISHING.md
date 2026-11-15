# Publication guide

This starter is prepared for the GitHub account **doooriian**. The original `CPP00` to `CPP09` repositories are currently private.

## 1. Import the tracked C++ sources

Extract the archive and, from the `CPP-Modules` directory, run:

```bash
./scripts/import-sources.sh
```

The default uses SSH (`git@github.com`), so your GitHub SSH key must have access to the private repositories. To use HTTPS authentication instead:

```bash
./scripts/import-sources.sh --https
```

The importer clones the ten source repositories into a temporary directory, then exports **only files tracked in each repository's latest commit**. It does **not** copy their `.git` histories or your locally untracked data. It refuses to replace already-imported exercise directories.

## 2. Review before making anything public

- Confirm that all ten module folders have their actual `exNN` code directories.
- Review the code and any embedded school login, author email, file paths or credentials before publication.
- Verify that everything you plan to publish is yours to share under applicable school rules.
- **CPP09/ex00 requires `data.csv`**, which is not part of the inspected source repo. Do not fabricate or publish a third-party dataset without permission.
- Optionally run `./scripts/check-builds.sh` to compile each exercise. A build check is not a comprehensive test suite. Review any errors before publication.
- There is no need to copy your private repositories' Git commit histories into the public portfolio.

## 3. Publish as a new public repository

### GitHub CLI (convenient on macOS)

If you have [GitHub CLI](https://cli.github.com/) installed and authenticated with `gh auth login`, run from `CPP-Modules`:

```bash
git init -b main
git add README.md CPP00 CPP01 CPP02 CPP03 CPP04 CPP05 CPP06 CPP07 CPP08 CPP09 scripts .gitignore PUBLISHING.md
git commit -m "docs: showcase 42 C++98 modules"
gh repo create doooriian/CPP-Modules --public --source=. --remote=origin --push
```

The `gh repo create` command **publishes the imported code**, so review it first.

### GitHub website alternative

Create an empty **public** repository named `CPP-Modules` on GitHub without initializing a README, then:

```bash
git init -b main
git add .
git commit -m "docs: showcase 42 C++98 modules"
git remote add origin git@github.com:doooriian/CPP-Modules.git
git push -u origin main
```

## 4. Final touches

- **Repository description:** `C++98 exercises from the 42 curriculum — OOP, memory, polymorphism, templates, STL and algorithms.`
- **Topics:** `42`, `42-school`, `cpp`, `cpp98`, `object-oriented-programming`, `templates`, `stl`, `algorithms`.
- Consider pinning it on your GitHub profile, ideally alongside `ft_transcendence` and `minishell`.
- Update your GitHub profile README with the URL **after** the repository exists and the publication is verified.
