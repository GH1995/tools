set nocompatible " 去除VI一致性,必须
filetype off     " 必须

" 设置包括vundle和初始化相关的runtime path
set rtp+=~/.vim/bundle/Vundle.vim
set rtp+=~/.vim
call vundle#begin()

" 让vundle管理插件版本,必须
Plugin 'VundleVim/Vundle.vim'

" YouCompleteMe
Plugin 'Valloric/YouCompleteMe'
" ~/.vim/vimrc/config/YouCompleteMe.vim

" lib
Plugin 'vim-scripts/L9'

" Airline: 小巧美观的状态栏
Plugin 'bling/vim-airline' " ~/.vim/vimrc/config/vim-airline.vim
Plugin 'vim-airline/vim-airline-themes'
" ~/.vim/vimrc/config/

" supertab
Plugin 'ervandew/supertab'
" ~/.vim/vimrc/config/

" 目录树
Plugin 'scrooloose/nerdtree'
" ~/.vim/vimrc/config/

" CtrlP
Plugin 'ctrlpvim/ctrlp.vim' " ~/.vim/vimrc/config/ctrlp.vim

" Markdown
" Plugin 'plasticboy/vim-markdown'
" Plugin 'godlygeek/tabular'
" Plugin 'tpope/vim-markdown'
" Plugin 'jtratner/vim-flavored-markdown'
" Plugin 'rhysd/vim-gfm-syntax'

" surround
Plugin 'tpope/vim-surround'
" ~/.vim/vimrc/config/

" vim-repeat
Plugin 'tpope/vim-repeat'
" ~/.vim/vimrc/config/

" 解决<C-W>O的问题
" Plugin 'itspriddle/ZoomWin'

" 区域选中
Plugin 'terryma/vim-expand-region' " ~/.vim/vimrc/config/vim-expand-region.vim

" 语法检查
Plugin 'w0rp/ale' " ~/.vim/vimrc/config/ale.vim
" Plugin 'vim-syntastic/syntastic'

" 括号补全
Plugin 'Raimondi/delimitMate'
" ~/.vim/vimrc/config/

" 文件编码
Plugin 'mbbill/fencview'
" ~/.vim/vimrc/config/

" Python 语法高亮
" Plugin 'vim-scripts/python.vim'

" 删除多余的空格
Plugin 'bronson/vim-trailing-whitespace'
" ~/.vim/vimrc/config/

" 缩进提示线
Plugin 'Yggdroot/indentLine'
" ~/.vim/vimrc/config/

" 自动格式化
Plugin 'tell-k/vim-autopep8'
" ~/.vim/vimrc/config/

" 高亮当前行
Plugin 'miyakogi/conoline.vim'
" ~/.vim/vimrc/config/

" 配色
" Plugin 'altercation/vim-colors-solarized'
" ~/.vim/vimrc/config/

" 折叠
Plugin 'tmhedberg/SimpylFold' " ~/.vim/vimrc/config/SimpylFold.vim

" LaTeX
Plugin 'vim-latex/vim-latex'
" ~/.vim/vimrc/config/

" 智能注释
Plugin 'scrooloose/nerdcommenter' " ~/.vim/vimrc/config/nerdcommenter.vim

" 快速执行
Plugin 'thinca/vim-quickrun' " ~/.vim/vimrc/config/vim-quickrun.vim

" 成对标签补全
Plugin 'docunext/closetag.vim' " ~/.vim/vimrc/config/closetag.vim

" 大纲式导航
Plugin 'majutsushi/tagbar' " ~/.vim/vimrc/config/tagbar.vim

" 括号高亮
Plugin 'kien/rainbow_parentheses.vim' " ~/.vim/vimrc/config/rainbow-parentheses.vim

" 成对标签跳转
Plugin 'vim-scripts/matchit.zip'

" 快速对齐
Plugin 'junegunn/vim-easy-align' " ~/.vim/vimrc/config/vim-easy-align.vim

" 多光标操作
Plugin 'terryma/vim-multiple-cursors'
" ~/.vim/vimrc/config/vim-multiple-cursors.vim

" Git操作
Plugin 'tpope/vim-fugitive'

" 格式化C++
Plugin 'kana/vim-operator-user'
Plugin 'rhysd/vim-clang-format'

" 中文排版
Plugin 'hotoo/pangu.vim'


" TMUX
" Plugin 'christoomey/vim-tmux-navigator'

" Plugin 'Shougo/denite.nvim'
" Plugin 'majutsushi/tagbar'
" Plugin 'vim-ctrlspace/vim-ctrlspace'
" Plugin 'jreybert/vimagit'
" Plugin 'jmcantrell/vim-virtualenv'
" Plugin 'airblade/vim-gitgutter'
" Plugin 'pthrasher/conqueterm-vim'
" Plugin 'easymotion/vim-easymotion'
"Plugin 'hdima/python-syntax'
" 文件时光机 Plugin 'sjl/gundo.vim'


call vundle#end()" 必须
" filetype plugin indent on    " 必须 加载vim自带和插件相应的语法和文件类型相关脚本
" 忽视插件改变缩进,可以使用以下替代:
"filetype plugin on

" 简要帮助文档
" :PluginList  - 列出所有已配置的插件
" :PluginInstall    - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
" :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
" :PluginClean - 清除未使用插件,需要确认; 追加 `!` 自动批准移除未使用插件

" 查阅 :h vundle 获取更多细节和wiki以及FAQ
" 将你自己对非插件片段放在这行之后
