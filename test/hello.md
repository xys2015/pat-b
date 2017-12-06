更改vim高亮括号匹配颜色

vim括号匹配高亮显示在vim7.4版本, 默认就是开启的. 但是默认的括号匹配  
高亮的颜色是浅蓝色, 在亮瞎眼的同时, 严重影响我们写代码, 最明显的感受  
就是, 连续打出一对括号, 接下来不仔细看, 根本找不到光标在哪?

So, 怎么改? 在`~/.vimrc`配置文件中添加, 下面一行

	hi MatchParen ctermbg=DarkRed guibg=lightblue

其中`DarkRed`就是我们需要修改的颜色, 我这里改成了暗红色, 后面那个颜色  
暂时不知道有什么暖用, 不用管它. 其实我最想要的不是更改选中后, 括号的背  
景颜色, 而是直接更改这个括号本身的颜色, 但貌似vim暂时无法实现. 下面是  
更改后的效果图.

[1](1.jpg)

选择自己想要的颜色可以看这里

	http://www.runoob.com/try/color.php?color=Black

> 有些颜色名称, vim不支持, 这时候换一个就行

vim官方括号匹配帮助文档

	http://vimdoc.sourceforge.net/htmldoc/pi_paren.html#:DoMatchParen

赠品: 本人简易vim配置

```
set mouse=a        " 开启鼠标支持
set autoindent	   " 自动缩进

set tabstop=4      " 设置所有的tab和缩进, 为4个空格
set softtabstop=4
set shiftwidth=4
set expandtab      " 使用空格来替换tab

colorscheme desert
hi MatchParen ctermbg=DarkRed guibg=lightblue

```