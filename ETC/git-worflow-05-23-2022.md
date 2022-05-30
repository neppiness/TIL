[TIL on May 23rd, 2022](../TIL/2022/05/05-23-2022.md)
# **Git Workflow**

There are four fundamental elements for git
#### Local elements
- Workspace (working dir): project files on local storage
- Index (stage): proj. files prepared to create new version
- Local repository (HEAD): version history
#### The element on server
- Remote repository: ex) github repository

### Commands for workflow
#### Commands to workflow from working directory to remote repository
- `clone`: downloads the remote repository files into working dir. on local
- `add`: adds project files on working directory to the staging area
- `commit`: records the files on staging area to .git directory as a new project version. Changes are safely stored on local.
- `push`: update remote repo. version to local repo.

Because git is a decentralized version control system, a local repository stores the versions that is not pushed to remote yet

#### Commands to workflow from remote repository to working directory
- `fetch`: get remote repo. files and overwrite them to local repo. (⇔ `push`)
- `merge`: update local repository files to working dir. files
- `pull`: the shortcut to use `fetch` and `merge` at once

#### Commands to compare the differences
- `diff`: compare between the files in working dir. and stage
- `diff HEAD`: compare between the files in working dir. and local repo.

<br>

| ![Git Workflow Figure](..%5CTIL%5C2022%5Cimg%5C05-23-2022.png) |
| -------------------------------------------------------------- |
| <h5 align="center">Fig. 1. Git Workflow Figure in Reference</h5> |

___

### References
- [GIT Workflow - Georgia Tech - Software Development Process](https://youtu.be/3a2x1iJFJWc)