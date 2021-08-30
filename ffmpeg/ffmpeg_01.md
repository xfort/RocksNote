#### FFMPEG [官网](https://ffmpeg.org/)
* [官网命令文档](https://ffmpeg.org/documentation.html)

##### 1.视频转码/格式
```
//只转格式
ffmpeg -i lg22.mp4 -acodec copy -vcodec copy -f mov lg22.mov
//转为h264,码率5000k,帧率30
ffmpeg -i video.mp4 -vcodec h264 -b:v 5000k -r 30 -acodec aac out.mp4 
//webm格式 https://trac.ffmpeg.org/wiki/Encode/VP9
ffmpeg -i xx -c:v libvpx-vp9  -b:v 2000k -b:a 0 -c:a libopus xx.webm
```
##### 2.视频拼接
```
ffmpeg -i concat:"1.ts|2.ts" -c copy out.mp4 //原各个视频不做转码
```
##### 3.提取帧截图
```
//0.1秒处的截图
 ffmpeg -ss 0.1 -i video.mp4 -f image2 -y 1.jpg
```
##### 4.修改分辨率，DAR 显示宽高比，SAR 采样纵横比（表示横向的像素点数和纵向的像素点数的比值）；PAR - pixel aspect ratio，单个像素的宽高比，大多数情况像素宽高比为1:1，也就是一个正方形像素，如果不是1:1， 则该像素可以理解为长方形像素
```
ffmpeg -i videofile  -vf scale=1440:1080,setdar=4:3  outvideo -y
```
##### 5.镜像翻转
```
ffmpeg -i input.mkv -vf hflip hflip.mkv
```
##### 6.视频裁剪（0:01:26到0:11:00）
```
ffmpeg -i video.mp4 -ss 0:01:26 -c copy -to 0:11:00 video_out.mp4
```
##### 7.视频去水印，模糊水印，通过周围像素插值去除
```
ffmpeg -i JINUSEAN.mp4 -vf delogo=x=72:y=32:w=168:h=86,delogo=x=72:y=32:w=168:h=86, output.mp4
x,y为水印坐标，w,h为水印宽高,同时去除两个水印
```
