# C++ clock implement

只是個簡易版的鬧鐘，有興趣可以實做看看，因為難度很簡單，所以身為初心者也可以推給~~剛入火坑的~~程式初學者們

### __顏色設置（ＡＮＳＩ)__

突然覺得程式結果都沒顏色是不是太無趣，所以就找了些有趣的東西來為我的程式添加色彩（？

在ＯＳ中可以用printf顏色設置，如果沒在程式碼中設置顏色那麼在呼叫程式時寫echo也可以出現有顏色的結果，但是注意寫上-e ""，比如：

`echo -e ""`

我們能夠用ＡＮＳＩ來操作顏色、閃爍和高亮各式各樣的有趣動作，讓你的鬧鐘變得更多花樣，下面這張圖先看一下“ ”內的程式碼，程式碼有用到跳脫字元（Escape character），有時會用到需要把字串用成一串一串的，在這時用跳脫字元就會方便許多

##### 跳脫字元 指的是 脫離原字元的意思

##### 例如 `"` 原來在程式中是用來當作字串的開頭或結尾

##### 寫成 `\"` 就能在字串中當作單純的符號來看待

##### `\x1b`意指逃脫字元的起始，而`;`則是代表分隔，`[`代表輸入設定，`m`指設定輸出

準確來說，`\x1b[0;m`（重置）是CSI標準的格式，剛才舉例的格式中`\x1b`和`0`是SGR (Select Graphic Rendition) parameters

背景顏色 

40: 黑  
41: 紅  
42: 綠  
43: 黃  
44: 藍  
45: 紫  
46: 深綠  
47: 白色    

字體顏色：

30: 黑  
31: 紅  
32: 綠  
33: 黃  
34: 藍  
35: 紫  
36: 深綠  
37: 白色  

但是記住，printf出來後要把顏色改回去，除非你顏色沒有要改回來，不然都要用`\x1b[0;m`改回原本狀態

我寫下幾個我比較常用到的設置，其他還有很多，如果有興趣可以這裡參考：http://chunchaichang.blogspot.com/2011/07/printf.html

\x1b[1;m 設置高亮度
\x1b[4;m 下劃線
\x1b[5;m 閃爍
\x1b[7;m 反顯
\x1b[8;m 消隱
\x1b[0;m 重置

 **如果你用\033宣告轉義序列的開始也是可以代替\x1b，因此下圖中Blink我用\033舉例，但是我習慣用\x1b所以後面都用\x1b**

![color](https://scontent.frmq2-2.fna.fbcdn.net/v/t1.15752-9/144275469_2876524729297980_3632800823634370331_n.png?_nc_cat=107&ccb=2&_nc_sid=ae9488&_nc_ohc=rcz1tGezLpUAX9ghd_S&_nc_ht=scontent.frmq2-2.fna&oh=5e6dcee91b14bea21d246dd588c474f7&oe=603FBC82)

### __implement__

先顯示目前時間，然後輸入時間

![first](https://scontent.frmq2-2.fna.fbcdn.net/v/t1.15752-9/144647877_231547521985520_706511538132752595_n.png?_nc_cat=109&ccb=2&_nc_sid=ae9488&_nc_ohc=kTAlAG1xvyIAX9BQ8JA&_nc_ht=scontent.frmq2-2.fna&oh=8b2568ccac5aeb8cac25fb5f94c6cc61&oe=603F0082)

搭配`\a`的的聲音當鬧鈴，設置時間，選項有兩個：1.起床 2.繼續睡

![second](https://scontent.frmq2-2.fna.fbcdn.net/v/t1.15752-9/145437100_2859228864314705_396907238929915620_n.png?_nc_cat=103&ccb=2&_nc_sid=ae9488&_nc_ohc=xTD8s8zk2T4AX-pSiL9&_nc_ht=scontent.frmq2-2.fna&oh=6b2247862d61b10a410e3707b08ba0ae&oe=603F152F)

因為是貪睡鬧鈴，所以設置選2就會叫五聲，然後告訴你今日幸運物為何，然後還會讓你繼續選

![third](https://scontent.frmq2-1.fna.fbcdn.net/v/t1.15752-9/145678898_792457034674744_5544496261822610737_n.png?_nc_cat=105&ccb=2&_nc_sid=ae9488&_nc_ohc=EJfiXRO7fOgAX_VDX6D&_nc_oc=AQnyk_YZB156m0JJ5XmJTTE-jA1K060BjFG1W3O-4YDTgX3lKg7nCuJHXCch8Zt9SOIpEwaZL8h9Fvii4v4b_kHG&_nc_ht=scontent.frmq2-1.fna&oh=7fdaac1b30b99547caf5ac79bb690cb4&oe=604086BF)

而你選1的話就會猜謎或是土味情話  

然後就會結束

![forth](https://scontent.frmq2-2.fna.fbcdn.net/v/t1.15752-9/144153130_137416731538989_2596087400619191794_n.png?_nc_cat=104&ccb=2&_nc_sid=ae9488&_nc_ohc=dB29uJ4qWxMAX_ZxqJS&_nc_ht=scontent.frmq2-2.fna&oh=d079d8045875ba882316d59cfc3614fb&oe=6041BCC2)


以上就是簡易鬧鐘的概念，如果有人不知道怎麼設一秒出現一行的設定，這個在time.h函式庫裡面，只要找找就有
