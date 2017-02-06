" Vundle.vim  插件 {{{
set nocompatible              " 去除VI一致性,必须
filetype off                  " 必须

" 设置包括vundle和初始化相关的runtime path
set rtp+=~/.vim/bundle/Vundle.vim
set rtp+=~/.vim
call vundle#begin()
" 另一种选择, 指定一个vundle安装插件的路径
"call vundle#begin('~/some/path/here')

" 让vundle管理插件版本,必须
Plugin 'VundleVim/Vundle.vim'

" 以下范例用来支持不同格式的插件安装.
" 请将安装插件的命令放在vundle#begin和vundle#end之间.

" Github上的插件
" 格式为 Plugin '用户名/插件仓库名'
" Plugin 'tpope/vim-fugitive'
" Plugin 'Valloric/YouCompleteMe'

" Fugitive: Git 集成，强烈推荐！
" Plugin 'tpope/vim-fugitive'

" 终端配色方案
" Plugin 'jnurmine/Zenburn'

" Solarized 配色
Plugin 'altercation/vim-colors-solarized'

" Commentary: 快速注释
" Plugin 'tpope/vim-commentary'

" Airline: 小巧美观的状态栏
Plugin 'bling/vim-airline'

" Tabular: 自动对齐
" Plugin 'godlygeek/tabular'
 
" 修改记录
" Plugin 'sjl/gundo.vim'

" 目录树
Plugin 'scrooloose/nerdtree'

" 查找
" Plugin 'easymotion/vim-easymotion'

" CtrlP
Plugin 'ctrlpvim/ctrlp.vim'

" CtrlFS
" Plugin 'dyng/ctrlsf.vim'

" LaTeX
" Plugin 'vim-latex/vim-latex'

" Markdown
Plugin 'plasticboy/vim-markdown'
Plugin 'Chiel92/vim-autoformat'
Plugin 'tpope/vim-surround'

" 解决<C-W>O的问题
" Plugin 'itspriddle/ZoomWin'

" 百度翻译
Plugin 'drwx/baidu_trans.vim'

" 在线翻译
Plugin 'iamcco/dict.vim'

" peaksea 配色方案
Plugin 'vim-scripts/peaksea'

" 配色方案
Plugin 'mkarmona/colorsbox'

" 配色方案
Plugin 'tomasr/molokai'

" 移动行
" Plugin 'yueyoum/vim-linemovement'

" snipmate
Plugin 'MarcWeber/vim-addon-mw-utils'
Plugin 'tomtom/tlib_vim'
Plugin 'garbas/vim-snipmate'

" Optional:
Plugin 'honza/vim-snippets'

" LaTeX-suite
Plugin 'gerw/vim-latex-suite'

" Plugin 'OmniCppComplete'
" 来自 http://vim-scripts.org/vim/scripts.html 的插件
" Plugin '插件名称' 实际上是 Plugin 'vim-scripts/插件仓库名' 只是此处的用户名可以省略
" Plugin 'L9'
" Plugin 'fencview'

" 由Git支持但不再github上的插件仓库 Plugin 'git clone 后面的地址'
" Plugin 'git://git.wincent.com/command-t.git'
" 本地的Git仓库(例如自己的插件) Plugin 'file:///+本地插件仓库绝对路径'
" Plugin 'file:///home/gmarik/path/to/plugin'
" 插件在仓库的子目录中.
" 正确指定路径用以设置runtimepath. 以下范例插件在sparkup/vim目录下
" Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" 安装L9，如果已经安装过这个插件，可利用以下格式避免命名冲突
" Plugin 'ascenator/L9', {'name': 'newL9'}
" 你的所有插件需要在下面这行之前
call vundle#end()            " 必须
filetype plugin indent on    " 必须 加载vim自带和插件相应的语法和文件类型相关脚本
" 忽视插件改变缩进,可以使用以下替代:
"filetype plugin on

" 简要帮助文档
" :PluginList       - 列出所有已配置的插件
" :PluginInstall    - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
" :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
" :PluginClean      - 清除未使用插件,需要确认; 追加 `!` 自动批准移除未使用插件

" 查阅 :h vundle 获取更多细节和wiki以及FAQ
" 将你自己对非插件片段放在这行之后
" }}}

" Vimscript file settings {{{
augroup filetype_vim
    autocmd!
    autocmd FileType vim setlocal foldmethod=marker
augroup END
" }}}

" 一些基本设置 {{{

" 打开语法高亮 
syntax on 
" 设置缩进有三个取值cindent(c风格)、smartindent(智能模式，其实不觉得有什么智能)、autoindent(简单的与上一行保持一致) 
set cindent 
" 在windows版本中vim的退格键模式默认与vi兼容，与我们的使用习惯不太符合，下边这条可以改过来 
set backspace=indent,eol,start 
" 用空格键替换制表符 
:set expandtab 
" 制表符占4个空格 
set tabstop=4 
" 默认缩进4个空格大小 
set shiftwidth=4 
" 增量式搜索 
set incsearch 
" 高亮搜索 
set hlsearch 
" 设置行号
set number
" 有时中文会显示乱码，用一下几条命令解决 
let &termencoding=&encoding
set fileencodings=utf-8,gbk 
" 很多插件都会要求的配置检测文件类型 
filetype on 
filetype plugin on 
filetype indent on 
" 编码检测
" set fileencodings=ucs-bom,cp936,gb18030,big5,euc-jp,euc-kr,latin1

" 离开normal模式立即切换为英文输入法 
set noimdisable
" 共享系统剪贴板
set clipboard=unnamed

" 命令行补全以增强模式运行
set wildmenu
set wildmode=full

" 解决移动问题
nnoremap j gj
nnoremap k gk

" 解决ESC问题
inoremap jk <esc>

" 设置缓冲区
set hidden

" 设置查找路径
set path+=~/Documents/GitHub/**

" 设置字典，gitbash环境所限
set dictionary+=~/.vim/dict/british-english

" c-n and c-p
set complete-=k complete+=k

" 5秒自动保存一次
let autosave=5

" 自动保存
autocmd InsertLeave *.md write

" 设定新窗口位置
set splitright
set splitbelow

" 折叠
" set foldmethod=indent
" set foldlevel=99

" 很好玩的映射，稍后设置
" nnoremap <space> za

" }}}

" some command {{{

" 使vim识别md文件 
au BufRead,BufNewFile *.md set filetype=markdown

" CtrlP
set runtimepath^=~/.vim/bundle/ctrlp.vim

" easymotion's leader
" let g:EasyMotion_leader_key='<Space>'

" CtrlSF's leader
" nmap <C-F>f <Plug>CtrlSFPrompt

" 设置 markdown 折叠
" let g:vim_markdown_folding_level = 1

" Enable TOC window auto-fit
" let g:vim_markdown_toc_autofit = 1


" Text emphasis restriction to single-lines
" let g:vim_markdown_emphasis_multiline = 0


" Gundo
" nnoremap <F5> :GundoToggle<CR>

" 在线翻译
" let g:api_key = "1932136763"
" let g:keyfrom = "aioiyuuko"

" 
" let g:linemovement_up="<c-Up>"
" let g:linemovement_down="<c-Down>

map <C-T> <leader>e2c

" vim 打开后回到原来的位置
au BufReadPost * if line("'\"") > 0|if line("'\"") <= line("$")|exe("norm '\"")|else|exe "norm $"|endif|endif  

" }}}

" GUI {{{

" 背景颜色
if has('gui_running')
    set background=dark
    colorscheme solarized
else

endif

set guifont=Consolas:h11:cANSI
" set guifont=Monaco:h11:cANSI
" set guifont=Monaco:h11:cDEFAULT


"不显示工具/菜单栏
set guioptions-=T
set guioptions-=m
set guioptions-=L
set guioptions-=r
set guioptions-=b


if has('win32')    
	au GUIEnter * simalt ~x
else    
	au GUIEnter * call MaximizeWindow()
endif 

" 最大化窗口
function! MaximizeWindow()    
	silent !wmctrl -r :ACTIVE: -b add,maximized_vert,maximized_horz
endfunction

" }}}

" lab {{{

let mapleader='-'

" ev命令编辑VIMRC文件
nnoremap <leader>ev :vsplit $MYVIMRC<cr>

" sv命令source VIMRC文件
nnoremap <leader>sv :source $MYVIMRC<cr>

" let maplocalleader="\\"
" nnoremap <leader>d dd

" abbreviation
iabbrev waht    what
iabbrev adn     and

iabbrev @G     Guan Hua, tulingjiaoyu@gmail.com
iabbrev @C     Copyright 2017 Guan Hua, all rights reserved.

" }}}
