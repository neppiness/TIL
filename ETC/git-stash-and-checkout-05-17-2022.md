[TIL on May 17th, 2022](../../TIL/2022/05-17-2022.md)
# **Git Stash and Checkout Function**

### 1. stash
> **Syntax**
> ```t
> git stash branch <branchname> [<stash>]
> ```

<br>
 
> **Description**
> Use git stash when you want to record the current state of the working directory and the index, but want to go back to a clean working directory.
> The command saves your local modifications away and reverts the working directory to match the HEAD commit.
>
> The modifications stashed away by this command can be listed with:
> * git stash list,
> * inspected with git stash show,
> * and restored (potentially on top of a different commit) with git stash apply.
>
> Calling git stash without any arguments is equivalent to git stash push.
>
> A stash is by default listed as "WIP on branchname …​", but you can give a more descriptive message on the command line when you create one.
> 
> The latest stash you created is stored in refs/stash; older stashes are found in the *reflog* of this reference and can be named using the usual reflog syntax
> (e.g. stash@{0} is the most recently created stash, stash@{1} is the one before it, stash@{2.hours.ago} is also possible).
> 
> Stashes may also be referenced by specifying just the stash index (e.g. the integer n is equivalent to stash@{n}).

<br>

### 2. checkout
git-checkout: Switch branches or restore working tree files
 
> **Syntax**
> ```t
> git checkout [-q] [-f] [-m] [<branch>]
> ```

<br>

> **Description**
> Updates files in the working tree to match the version in the index or the specified tree.
> If no pathspec was given, git checkout will also update HEAD to set the specified branch as the current branch.

> **git checkout [&lt;branch&gt;]**
> To prepare for working on &lt;branch&gt;, switch to it by updating the index and the files in the working tree, and by pointing HEAD at the branch.
> Local modifications to the files in the working tree are kept, so that they can be committed to the &lt;branch&gt;.

___

### References
- [git-stash Document](https://git-scm.com/docs/git-stash)
- [git-checkout Document](https://git-scm.com/docs/git-checkout)