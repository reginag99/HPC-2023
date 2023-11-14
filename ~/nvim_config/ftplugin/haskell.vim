set number
set shell=/bin/sh

let tabstop=2
set expandtab
let shiftwidth=4
let softtabstop=4

let g:haddock_browser = "firefox"

" let g:syntastic_haskell_checkers = ['ghc-mod', 'hdevtools', 'hlint']
" let syntastic_auto_loc_list=1

" Hdevtools and Syntastic
map <silent> <Leader>te :Errors<CR>
map <Leader>ts :SyntasticToggleMode<CR>

" GHC mod
nnoremap <buffer> <silent> <C-t>t :GhcModType<CR>
nnoremap <buffer> <silent> <C-t>c :GhcModTypeClear<CR>
nnoremap <buffer> <silent> <C-t>i :GhcModInfo<CR>

" Hdevtools
nnoremap <buffer> <silent> <C-t>ht :HdevtoolsType<CR>
nnoremap <buffer> <silent> <C-t>hc :HdevtoolsClear<CR>
nnoremap <buffer> <silent> <C-t>hi :HdevtoolsInfo<CR>

" Hsimport
" nnoremap <buffer> <silent> <C-t>m :silent update <bar> HsimportModule<CR>
" nnoremap <buffer> <silent> <C-t>s :silent update <bar> HsimportSymbol<CR>
