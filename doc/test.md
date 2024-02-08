<div align = 'center'>
    <font size = "100"> markdowm 语法的演示 </font>
</div>

# 这是我的第一篇文章
## 这是我的第一篇文章
### 这是我的第一篇文章
#### 这是我的第一篇文章
##### 这是我的第一篇文章
###### 这是我的第一篇文章


这是我的正文
我换行了

**加粗**

*斜体*

1. 列表1
2. 列表2
   1. 列表2的二级标题1
   2. 列表2的二级标题2
      1. 列表2的二级标题2的三级标题1
3. 列表3


1. 这是什么

在两个列表中间加一些文字可以让列表从头编号

<br/>
<br/>
<br/>
<br/>
<br/>


![当图片显示不出来时就显示这段文字](image-1.png)  
*这是直接复制图片，然后粘贴的方法贴上图片， 这种方法会自动在 README 目录下创建图片（目前已经移动所以看不到）*






![](image/image-1.png)  
*这是通过链接的方法插入图片* 




#### 插入公式:

$$
x + y = 10
$$

在一段文字之间插入 $a + b = c$ 公式




## 表格 不打 : 默认左对齐 两个 : 默认居中对齐


| 小红 | 小明  | 小东 |
| ---- | :---: | ---: |
| 1.5  |  1.4  |  1.3 |
| 2.5  |  2.4  |  2.3 |



### 插入链接

这是一个链接https://www.bilibili.com/video/BV1JA411h7Gw/?spm_id_from=333.337.search-card.all.click&vd_source=f3567b80a457c55c069f442b981e43d6

这是[另一个链接](https://www.bilibili.com/video/BV1si4y1472o/?spm_id_from=333.337.search-card.all.click&vd_source=f3567b80a457c55c069f442b981e43d6)




## 插入代码块

~~~C++
    int main() {

        vector<pair<int, int>> arr;

        for (const auto& item : arr) cout << item.first << ' ' << item.second << endl;

        return 0;
    }
~~~



# 另一个视频里面的教学

### 引用

>这是一段引用

### 列表

有序列表:
1. 打开冰箱
2. 把大象放进冰箱
3. 关上冰箱
   
无序列表:
- 打开冰箱

* 把大象方静冰箱

- 关上冰箱

任务列表:
- [ ] 吃饭
- [ ] 睡觉
- [x] 打豆豆

### 代码块

~~~C++
int main() {

    vector<int> arr;

    // 遍历整个数组
    for (const auto& item : arr) printf("%d ", arr[i]);

    return 0;
}
~~~


### 数学公式
$$
a + b = c
$$


### 表格 至少要有一个 -

| 姓名 | 年龄 | 成绩  |
| ---- | ---: | :---: |
| 张三 |   12 |  124  |
| 李四 | 1212 |  123  |


### 脚注---分为脚注的链接和内容

一键三连[^三连]

[^三连]:点赞 投币 收藏


### 横线


---

我被横线包围了

---



### 链接 

[链接的名字](https://www.baidu.com/ "鼠标放上去会显示这个文字(要有空格)")



### 引用链接

[链接的名字][id]
[链接的名字][id]
[链接的名字][id]

[id]:https://www.baidu.com/ "文章中多次用到次链接不妨设为引用链接"





### 链接直接跳转到文中另一处

请参考[标题1](#这是我的第一篇文章)


### url---直接跳转

http://www.baidu.com



### 图片

![图片加载不出来时就会显示这个文字](image-2.png "鼠标放上去会有字")



### 其他的一些小杂项

*斜体*

**加粗**

`printf()`

<u> 下划线 </u>

:smile:

$ a + b + c = 100 $

H~2~O

x^2^

==高亮文字==


### 嵌入代码对视频进行播放

<iframe src="//player.bilibili.com/player.html?aid=327623069&bvid=BV1JA411h7Gw&cid=171385214&p=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>


这个编辑器不兼容