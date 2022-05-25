[TIL on May 22nd, 2022](../../TIL/2022/05-22-2022.md)
# **Reverting functions of Git**

**NOTE: Work flow of git must be preceded**
### 1. Revert 'add'
- If some changes not intended to be put are added on staging area by 'add' command, git reset HEAD [file] command may be used to cancel it
- For example:

```shell
// Make CONTRIBUTING.md file Unstage
$ git reset HEAD CONTRIBUTING.md
Unstaged changes after reset:
M	CONTRIBUTING.md
```

### 2. Revert 'commit'
- Likewise, 'commit' can be cancelled by the commands below:

```shell
// [Option 1] Cancel a commit and preserve the files in working dir. as staged status 
$ git reset --soft HEAD^
// [Option 2] Cancel a commit and preserve the files in working dir. as unstaged status
$ git reset --mixed HEAD^ // default option
$ git reset HEAD^ // same as above
$ git reset HEAD~2 // Cancel last 2 commits as the description of option 2
// [Option 3] Cancel a commit and delete the files in working dir. as unstaged status
$ git reset --hard HEAD^
```

#### 2-1. Modify the commit message
- If commit message needs to be modified, `git commit –amend` command could be used to modify it.


### 3. Revert 'push'
- If `git push` command is reverted, your local directory files are forced to be overwritten by remote
  - Then, all the information modified after the time of the loaded 'commit' was originally committed is lost
  - Also, especially for collaboration projects, it is neccessary to communicate with teammates because some synchronization problems can occur from this function 

- Revert commit from working directory.
```shell
// cancel recent commit (default: --mixed)
$ git reset HEAD^
```

- Bring Working directory back to the desirable time 
```shell
// Check Reflog(the list of commits that branches and HEAD pointed)
$ git reflog // (or $ git log -g)

$ git reset HEAD@{number} // (or $ git reset [commit id])
```
___

### References
- [깃 중요 컨셉 (workflow) section of 깃, 깃허브 제대로 배우기 (기본 마스터편, 실무에서 꿀리지 말자)](https://youtu.be/Z9dvM7qgN9s?t=987)
- [[Git] git add 취소하기, git commit 취소하기, git push 취소하기](https://gmlwjd9405.github.io/2018/05/25/git-add-cancle.html)