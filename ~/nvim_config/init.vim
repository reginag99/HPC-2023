inoremap <silent> <C-A-h> <C-o>h
inoremap <silent> <C-A-j> <C-o>j
inoremap <silent> <C-A-k> <C-o>k
inoremap <silent> <C-A-l> <C-o>l

set backup
set backupdir=~/.local/share/nvim/backup

runtime macros/matchit.vim

call plug#begin()
Plug 'icymind/NeoSolarized'

Plug 'tmux-plugins/vim-tmux-focus-events'
Plug 'roxma/vim-tmux-clipboard'

Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'majutsushi/tagbar', { 'on': 'TagbarToggle' }
Plug 'vim-airline/vim-airline'
Plug 'jpalardy/vim-slime'

Plug 'tpope/vim-unimpaired'
Plug 'Konfekt/FastFold'
Plug 'godlygeek/tabular'

Plug 'neomake/neomake'

Plug 'Shougo/neosnippet'
Plug 'Shougo/neosnippet-snippets'
Plug 'Shougo/deoplete.nvim'

Plug 'Shougo/vimproc.vim'

Plug 'tpope/vim-fugitive'
" Plug 'airblade/vim-gitgutter', { 'on': 'GitGutterToggle' }

Plug 'tpope/vim-markdown', { 'for': 'markdown' }
" Plug 'baruchel/vim-notebook', { 'for': 'jlmd' }

Plug 'lervag/vimtex', { 'for': 'tex' }

Plug 'JuliaLang/julia-vim' ", { 'for': 'julia' } otherwise this yields errors aobut Unicode functions
" Plug 'zyedidia/julialint.vim', { 'for': 'julia' }

" Plug 'bitc/vim-hdevtools', { 'for': 'haskell' }
Plug 'eagletmt/ghcmod-vim', { 'for': 'haskell' }
Plug 'eagletmt/neco-ghc', { 'for': 'haskell' }
call plug#end()


filetype plugin indent on


let g:python_host_prog = '/usr/bin/python'
let g:python3_host_prog = '/usr/bin/python3'


set termguicolors
colorscheme NeoSolarized
set background=dark
let g:neosolarized_contrast = "normal"
let g:neosolarized_visibility = "high"

set ruler

set incsearch


nmap <silent> <F2> :NERDTreeToggle<CR>
nmap <silent> <F3> :TagbarToggle<CR>
let g:tagbar_autofocus = 1

" NEOTAGS seems promising, but I could not make it run
" Plug 'c0r73x/neotags.nvim'
" nmap <silent> <F3> :NeotagsToggle<CR>
" Fedora 26 comes with ctags that takes --extra instead of --extras
" let g:neotags_ctags_args = '--fields=+l --c-kinds=+p --c++-kinds+p --sort=no --extra=+q'

let g:slime_target = "tmux"
let g:slime_paste_file = tempname()

autocmd! BufWritePost * Neomake


imap <C-k> <Plug>(neosnippet_expand_or_jump)

"I could not make deoplete work for latex
"let g:deoplete#enable_at_startup = 1
"let g:deoplete#disable_auto_complete = 1
"let g:deoplete#enable_smart_case = 1
"inoremap <expr><C-g> deoplete#undo_completion()
"inoremap <expr><C-l> deoplete#complete_common_string()



let mapleader = "\<SPACE>"

nmap <silent> <Leader><Leader>m :make<CR>



"todo: use different file name for local rc
let thisdir = expand("%:p:h")
let vimrclocal = thisdir . "/.vimrc.local"
if (filereadable(vimrclocal))
    execute "source " . vimrclocal
endif
