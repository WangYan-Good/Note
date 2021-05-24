GIT USAGE

1. AGENDA
  Basic Concept of Git
  Git Tools (git and tortoisegit)
  Git Setting (.gitconfig and .ssh / config)
  Clone (submodule)
  Remote (add / remove)
  Branch (add / remove / switch)
  Update (pull, fetch, rebase, reset, push)
  Patch (add, commit, cherry-pick, am, format-patch, send-email)
  Log (show, log)
  GitHub Pull Request / GitLib Merge Request

2. WHAT'S GIT
  �ֲ�ʽ�Ĵ��������
  �����޸���ʷ�������ڱ���
  ��֤�洢��������
  ���е��޸Ķ��ǵ�����
  ֧�ֶ��Զ�˵�Դ����
  ֧�ֶ����֧
  ֧�ֱ�ǩ
  ֧�ֲ�ͬ��֧֮��ĸ���ͬ������

3. CLONE
  HTTP
  git clone url directory

  SSH
  git clone git@github.com:tianocore / edk2.git -b master directory
  cd directory
  git submodule update --init

4. REMOTE
  Add Remote
    git remote add remote_name https://github.com/url

  Show Remote
    git remote -v

  Remove Remote
    git remote remove remote_name

4. UPDATE
  Fetch remote update
    git fetch origin

  Update local code
    git rebase origin / master
    git reset origin / master --hard
    git pull origin --> git fetch origin & git rebase origin / master

  Push local commit to remote
    git push origin local_brach:remote_branch

5. PATCH
  Add new commits
    git status
    git add changed_file
    git commit -m "commit message"

  Revert the commits
    git reset HEAD~n
    git reset HEAD~n --hard

  Create git pathches
    git format-patch  -n
    git send-email *.patch

  Apply git patches
    git am --3way --ignore-space-change --keep-cr *.patch
    git cherry-pick commit_hase_value

6. LOG
  Show logs
    git log --oneline
    git log --oneline -n origin / master
    git log --oneline commit_start ..commit_end
    git log --pretty=tformat:"%h %<(15)%aN %cD %s" -n
