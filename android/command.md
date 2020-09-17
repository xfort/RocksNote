### Android 常用命令
 
#### 1.adb导出apk
```
adb shell pm list packages
adb shell pm path com.huawei.camera
adb pull /system/priv-app/HwCamera2/HwCamera2.apk  C:/Users/fly/Desktop

```
#### 2.apksigner签名打包 v1、v2
官方文档 https://developer.android.com/studio/command-line/apksigner.html?hl=zh_cn
```
apksigner sign --ks xxkeystorefile --ks-key-alias xxalias --ks-pass pass:xxKSPass --key-pass pass:xxKeyPass --v2-signing-enabled true --out out.apk source.apk

验证签名,最低android版本
apksigner verify --min-sdk-version 21 app-name.apk

```

#### 3.zipalign对齐
如果使用的是 apksigner，则只能在为 APK 文件签名之前执行 zipalign；
如果使用的是 jarsigner，则只能在为 APK 文件签名之后执行 zipalign。
```
zipalign [-f] [-v] <alignment> infile.apk outfile.apk

检查对齐方式
zipalign -c -v <alignment> existing.apk

-f：覆盖现有的 outfile.zip
-v：详细输出
-p：outfile.zip 应对 infile.zip 中的所有共享对象文件使用相同的页面对齐方式
-c：确认给定文件的对齐方式

```

#### 4.查看签名证书信息
```
 keytool -list -v -keystore debug.keystore \\查看 keystore
 keytool -printcert -file META-INF/CERT.RSA \\从APK文件提取解压出META-INF文件夹的RSA
```