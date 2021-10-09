
"渲染Tab和空格
set listchars=tab:?\ ,trail:? 
"在三种模式下采用三种光标[仅gVim]
let &t_SI = "\<Esc>]50;CursorShape=1\x7"
let &t_SR = "\<Esc>]50;CursorShape=2\x7"
let &t_EI = "\<Esc>]50;CursorShape=0\x7"
"自动缩进
set autoindent
"设置字体[仅gVim]
set guifont=Powerline_Consolas:h12:cANSI:qDRAFT
"自动换行
set wrap
"输入命令的时候Tab显示提示
set wildmenu
"复制粘贴到剪贴板
vnoremap <Leader>y "+y
nmap <Leader>p "+p

set ambiwidth=double                    " 设置为双字宽显示，否则无法完整显示如:☆ 
let g:airline_theme='bubblegum'     "Airline主题
let g:airline_powerline_fonts = 1
" 开启tabline
let g:airline#extensions#tabline#enabled = 1      "tabline中当前buffer两端的分隔字符
let g:airline#extensions#tabline#left_sep = ' '   "tabline中未激活buffer两端的分隔字符
let g:airline#extensions#tabline#left_alt_sep = '|'      "tabline中buffer显示编号
let g:airline#extensions#tabline#buffer_nr_show = 1
" 映射切换buffer的键位
nnoremap [b :bp<CR>
nnoremap ]b :bn<CR>


set guioptions-=m   "Hide Menu
set guioptions-=T   "Hide Tool-Bar
set guioptions-=r   "hide right scroll
set guioptions-=b   "hide buttom scoll
set guioptions-=L   "hide left scroll


"始终开启标志列
let g:ale_sign_column_always = 1
let g:ale_set_highlights = 0
"自定义error和warning图标
let g:ale_sign_error = '? '
let g:ale_sign_warning = '<d83d><dd30>'




"行号
set number
"高亮显示
"syntax on
"syntax enable
"底部显示当前处于什么模式
set showmode
"命令显示
set showcmd
"使用鼠标
"set mouse=a
"utf-8编码
set encoding=utf-8
"用256色
set t_Co=256
"文件类型检查
filetype indent on
"缩进相同
set autoindent
"Tab显示空格数
set tabstop=4
"自动吧Tab转为空格
set expandtab
"Tab空格数
set softtabstop=4
"当前行高亮
set cursorline
"行宽
set textwidth=80
set wrap
set linebreak

set laststatus=2
"当前位置
set ruler
set showmatch

set hlsearch

set incsearch

set ignorecase

"set spell spelllang

set undofile

set autochdir

set noerrorbells

set history=1000

set wildmenu
set wildmode=longest:list,full

"括号自动补全
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {}<ESC>i
inoremap < <><ESC>i

filetype plugin indent on


call plug#begin('~/.vim/plugged')
"Plug 'valid git URL'
Plug 'linuxidc/linux'
Plug 'vim-airline/vim-airline'
Plug 'bling/vim-airline'
Plug 'skywind3000/vim-dict'
call plug#end()

"----------------------------------------------------------------
"编码设置
"----------------------------------------------------------------
"Vim 在与屏幕/键盘交互时使用的编码(取决于实际的终端的设定)        
set encoding=utf-8
set langmenu=zh_CN.UTF-8
" 设置打开文件的编码格式  
set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1
set fileencoding=utf-8
"解决菜单乱码
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
"解决consle输出乱码
"set termencoding = cp936  
"设置中文提示
language messages zh_CN.utf-8
"设置中文帮助
set helplang=cn
"设置为双字宽显示，否则无法完整显示如:☆ 
set ambiwidth=double


let g:airline_theme="luna"

"这个是安装字体后 必须设置此项" 
let g:airline_powerline_fonts = 1

 "打开tabline功能,方便查看Buffer和切换，这个功能比较不错"
 "我还省去了minibufexpl插件，因为我习惯在1个Tab下用多个buffer"
 let g:airline#extensions#tabline#enabled = 1
 let g:airline#extensions#tabline#buffer_nr_show = 1

 "设置切换Buffer快捷键"
 nnoremap <C-N> :bn<CR>
 nnoremap <C-P> :bp<CR>

 " 关闭状态显示空白符号计数,这个对我用处不大"
 let g:airline#extensions#whitespace#enabled = 0
 let g:airline#extensions#whitespace#symbol = '!'

" 在Gvim中我设置了英文用Hermit， 中文使用 YaHei Mono "
if has('win32')
  set guifont=Hermit:h13
  set guifontwide=Microsoft_YaHei_Mono:h12
endif


let g:airline_theme="luna"

"这个是安装字体后 必须设置此项"
let g:airline_powerline_fonts = 1

 "打开tabline功能,方便查看Buffer和切换，这个功能比较不错"
 "我还省去了minibufexpl插件，因为我习惯在1个Tab下用多个buffer"
 let g:airline#extensions#tabline#enabled = 1
 let g:airline#extensions#tabline#buffer_nr_show = 1

 "设置切换Buffer快捷键"
 nnoremap <C-N> :bn<CR>
 nnoremap <C-P> :bp<CR>

 " 关闭状态显示空白符号计数,这个对我用处不大"
 let g:airline#extensions#whitespace#enabled = 0
 let g:airline#extensions#whitespace#symbol = '!'

" 在Gvim中我设置了英文用Hermit， 中文使用 YaHei Mono "
if has('win32')
  set guifont=YaHei Mono:h13
  set guifontwide=Microsoft_YaHei_Mono:h12
endif

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" 高亮显示普通txt文件（需要txt.vim脚本）
au BufRead,BufNewFile *  setfiletype txt

"自动补全
:inoremap ( ()<ESC>i
:inoremap ) <c-r>=ClosePair(')')<CR>
:inoremap { {<CR>}<ESC>O
:inoremap } <c-r>=ClosePair('}')<CR>
:inoremap [ []<ESC>i
:inoremap ] <c-r>=ClosePair(']')<CR>
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i
function! ClosePair(char)
    if getline('.')[col('.') - 1] == a:char
        return "\<Right>"
    else
        return a:char
    endif
endfunction
filetype plugin indent on

"打开文件类型检测, 加了这句才可以用智能补全
set completeopt=longest,menu

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""新文件标题""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"新建.c,.h,.sh,.java文件，自动插入文件头
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()"
""定义函数SetTitle，自动插入文件头
func SetTitle()
    "如果文件类型为.sh文件
    if &filetype == 'sh'
        call setline(1,"\#########################################################################")
        call append(line("."), "\# File Name: ".expand("%"))
        call append(line(".")+1, "\# Author: Klack_K")
        call append(line(".")+2, "\# mail: xzp01@foxmail.com")
        call append(line(".")+3, "\# Created Time: ".strftime("%c"))
        call append(line(".")+4, "\#########################################################################")
        call append(line(".")+5, "\#!/bin/bash")
        call append(line(".")+6, "")
    else
        call setline(1, "/*************************************************************************")
        call append(line("."), "    > File Name: ".expand("%"))
        call append(line(".")+1, "    > Author: Black_K")
        call append(line(".")+2, "    > Mail: xzp01@foxmail.com ")
        call append(line(".")+3, "    > Created Time: ".strftime("%c"))
        call append(line(".")+4, " ************************************************************************/")
        call append(line(".")+5, "")
    endif

    if &filetype == 'cpp'
        call append(line(".")+6, "#include<iostream>")
        call append(line(".")+7, "using namespace std;")
        call append(line(".")+8, "")
    endif

    if &filetype == 'c'
        call append(line(".")+6, "#include<stdio.h>")
        call append(line(".")+7, "#include<unistd.h>")
        call append(line(".")+8, "#include<stdlib.h>")
        call append(line(".")+9, "#include<string.h>")
        call append(line(".")+10, "")
        call append(line(".")+11, "int main(int argc,char* argv[]){")
        call append(line(".")+12, "\/\/\"start coding K:\"")
        call append(line(".")+13, "")
        call append(line(".")+14, "    return 0;")
        call append(line(".")+15, "}")
    endif

    "新建文件后，自动定位到文件末尾
    autocmd BufNewFile * normal G
endfunc

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""     
