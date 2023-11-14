filetype plugin indent on

set expandtab
set shiftwidth=2

set scrolloff=10
set number

let g:tagbar_type_julia = {
    \ 'ctagstype' : 'julia',
    \ 'kinds'     : ['a:abstract', 'i:immutable', 't:type', 'f:function', 'm:macro']
    \ }

let g:neomake_julia_enabled_makers = []
