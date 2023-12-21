" Set line numbers "
set number
set relativenumber

" Enable use of the mouse "
if has('mouse')
	set mouse=a
endif

" Search options "
set ignorecase
set incsearch
set hlsearch

" Show tabline "
set showtabline=2
set tabpagemax=14

" Change the direction of new splits "
set splitbelow
set splitright

runtime! ftplugin/man.vim
