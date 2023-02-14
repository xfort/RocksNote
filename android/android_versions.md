## Android各版本变化

官方文档 https://developer.android.com/about/versions/13/summary?hl=zh-cn

### android 13 API 33变更-[官方文档](https://developer.android.com/about/versions/13/behavior-changes-all?hl=zh-cn)
*通知的运行时权限：POST_NOTIFICATIONS
##### 1.前台服务 (FGS) 任务管理器。
从 Android 13（API 级别 33）开始，前台服务显示在通知栏，被停止后，整个app会被杀死，并不会发送任何回调。
如果系统检测到您的应用长时间运行某项前台服务（在 24 小时的时间段内至少运行 20 小时），便会发送通知邀请用户与 FGS 任务管理器互动。满足以下任一条件，系统将不会显示此通知：
`显示了与前台服务相关的通知。也就是说，用户尚未滑动关闭相应通知;
前台服务的类型为 FOREGROUND_SERVICE_TYPE_MEDIA_PLAYBACK 或 FOREGROUND_SERVICE_TYPE_LOCATION。`

以下应用可以运行前台服务，而完全不会显示在任务管理器中：
`系统级应用;安全应用，即具有 ROLE_EMERGENCY 角色的应用;处于演示模式的设备上的应用`
当以下类型的应用运行前台服务时，它们会显示在 FGS 任务管理器中，但应用名称旁边没有可以供用户按的停止按钮：
`设备所有者应用;资料所有者应用;常驻应用;具有 ROLE_DIALER 角色的应用`
##### 2.利用 JobScheduler
应用可使用 JobInfo.Builder.setPrefetch() 将特定作业标记为“预提取”作业，理想情况下这些作业应该在应用下一次启动前提前一点运行。在 Android 13（API 级别 33）及更高版本中

##### 3.Android 13（API 级别 33）引入了运行时通知权限
POST_NOTIFICATIONS。 此更改有助于用户专注于最重要的通知。例外：在前台服务 (FGS) 任务管理器中看到与前台服务相关的通知，但在抽屉式通知栏中不会看到此类通知；与媒体会话有关的通知；自行管理通话的应用
##### 4.intent 过滤器会屏蔽不匹配的 intent。
仅当该 intent 与接收应用中的 <intent-filter> 元素匹配时，系统才会传送该 intent
##### 5.在搭载 Android 13 或更高版本的设备上，用户可以默认关闭与前台服务相关联的通知。
##### 6.移除了旧版语音服务实现副本。
应用应使用设备的 SpeechService 默认提供程序，而不是硬编码为特定应用。

##### 7.如果用户拒绝授予通知权限，就不会在抽屉式通知栏中看到与前台服务相关的通知。
 不过，无论是否授予通知权限，用户都会在前台服务 (FGS) 任务管理器中看到与前台服务相关的通知。
##### 8.针对附近 Wi-Fi 设备的新运行时权限。
只要您的应用不会通过 Wi-Fi API 推导物理位置，那么当您以 Android 13 或更高版本为目标平台并使用 Wi-Fi API 时，就可以请求 NEARBY_WIFI_DEVICES 而不是 ACCESS_FINE_LOCATION。当您声明 NEARBY_WIFI_DEVICES 权限时，请强烈断言您的应用绝不会通过 Wi-Fi API 推导物理位置信息
##### 9.细化的媒体权限。
需要访问其他应用已经创建的媒体文件，您必须请求以下一项或多项细化的媒体权限，而不是READ_EXTERNAL_STORAGE 权限。图片和照片	READ_MEDIA_IMAGES；视频	READ_MEDIA_VIDEO；音频文件	READ_MEDIA_AUDIO。
如果您的应用只需要访问图片、照片和视频，请考虑使用照片选择器

##### 10.在后台使用身体传感器需要新的权限 BODY_SENSORS_BACKGROUND

以下是新功能
##### a.预测性返回手势
##### b.蓝牙 LE 音频.低功耗 (LE) 音频是一种无线音频
##### c.提高了 Splash Screen API 中的动画启动画面的效率
##### d.更安全地导出上下文注册的接收器
##### e.照片选择器.无需声明任何运行时权限
##### f.可编程的着色器
##### g.改善了防手掌误触.Android 13 通过为动作事件对象添加 FLAG_CANCELED 而增强了手掌误触识别.在收到 ACTION_POINTER_UP 时检查 FLAG_CANCELED，以确保已检测和处理手掌误触和其他取消的事件


### android 12 API 31-32 变更-[官方文档](https://developer.android.com/about/versions/12/behavior-changes-all?hl=zh-cn)

##### A.自定义通知
对于以 Android 12 为目标平台的应用，包含自定义内容视图的通知将不再使用完整通知区域；相反，系统会应用标准模板。会影响某些定义 Notification.Style 的自定义子类的应用，或使用 Notification.Builder 的方法 setCustomContentView(RemoteViews)、setCustomBigContentView(RemoteViews) 和 setCustomHeadsUpContentView(RemoteViews) 的应用。
如果您的应用使用的是完全自定义的通知，我们建议您尽快使用新模板进行测试。
所有通知都是可展开的。通常，这意味着，如果您使用的是 setCustomContentView，则还需要使用 setBigCustomContentView，以确保收起状态和展开状态保持一致。
自定义视图的尺寸已更改。一般来说，提供给自定义通知的高度比之前小。在收起状态下，自定义内容的最大高度已从 106dp 减少到 48dp。此外，水平空间也减小了
##### B.前台服务启动限制
以 Android 12 或更高版本为目标平台的应用无法在后台运行时启动前台服务，少数特殊情况除外。如果应用尝试在后台运行时启动前台服务，则会引发异常（少数特殊情况除外）。

当您的应用在后台运行时，请考虑使用 WorkManager 来计划和启动加急工作。如需完成用户请求的紧急操作，请按照精确的闹钟启动前台服务。
##### C.通知 trampoline 限制
应用无法从用作通知 trampoline 的服务或广播接收器中启动 activity。换言之，当用户点按通知或通知中的操作按钮时，您的应用无法在服务或广播接收器内调用 startActivity()。
如果您的应用从充当通知 trampoline 的服务或广播接收器启动 activity，请完成以下迁移步骤：
`创建一个与用户点按通知后看到的 activity 关联的 PendingIntent 对象。`
`在构建通知的过程中，使用您在上一步中创建的 PendingIntent 对象。`


##### 1.应用启动画面 SplashScreen  API (compat兼容库)
从 Android 12 开始，在所有应用的冷启动和温启动期间，系统始终会应用新的 Android 系统默认启动画面。 默认情况下，此系统默认启动画面由应用的启动器图标元素和主题的 windowBackground（如果是单色）构成
##### 2.网络 intent 解析
从 Android 12（API 级别 31）开始，仅当您的应用获准处理某个通用网络 intent 中包含的特定网域时，该网络 intent 才会解析为应用中的 activity。如果您的应用未获准处理相应的网域，则该网络 intent 会解析为用户的默认浏览器应用
##### 3.Display#getRealSize 和 getRealMetrics：废弃和限制
应用应使用 WindowMetrics API 查询其窗口的边界，并使用 Configuration.densityDpi 查询当前的密度。
为了与较低的 Android 版本实现更广泛的兼容性，您可以使用 Jetpack WindowManager 库，它包含一个 WindowMetrics 类，该类支持 Android 4.0（API 级别 14）及更高版本。
##### 4.Android 12 将多窗口模式作为标准行为。
在大屏设备 (sw >= 600dp) 中，所有应用都将在多窗口模式下运行，无论应用配置为何。如果 resizeableActivity="false"，应用会在必要时进入兼容模式，以适应显示屏尺寸。

在小屏设备 (sw < 600dp) 中，系统会检查 activity 的 minWidth 和 minHeight，来确定 activity 能否在多窗口模式下运行。如果 resizeableActivity="false"，则无论最小宽度和高度如何，应用都无法在多窗口模式下运行。

##### 5.受限应用待机模式存储分区
从 Android 12 开始，此存储分区默认处于活跃状态。在所有存储分区中，受限存储分区的优先级最低（限制最高）.
受限：应用会消耗大量的系统资源，或表现出不良行为。
##### 6.大致位置
在搭载 Android 12 或更高版本的设备上，用户可以要求您的应用只能访问大致位置信息。
如果您的应用请求 ACCESS_COARSE_LOCATION 但未请求 ACCESS_FINE_LOCATION，则此变更不会影响您的应用。
如果您的应用请求 ACCESS_FINE_LOCATION 运行时权限，您还应请求 ACCESS_COARSE_LOCATION 权限，以便处理用户授予应用大致位置访问权限的情形。您应该在单个运行时请求中包含这两项权限。
##### 7.麦克风和摄像头切换开关
在搭载 Android 12 或更高版本的受支持设备上，用户可以通过按一个切换开关选项，为设备上的所有应用启用和停用摄像头和麦克风使用权限。用户可以从快捷设置访问可切换的选项（如图 1 所示），也可以从系统设置中的“隐私设置”屏幕访问。
##### 8.Android 12 移除了之前弃用的加密算法的许多 BouncyCastle 实现，包括所有 AES 算法。系统改用这些算法的 Conscrypt 实现。
##### 9.应用无法关闭系统对话框
从 Android 12 开始，弃用了 ACTION_CLOSE_SYSTEM_DIALOGS intent 操作。除了一些特殊情况之外，当应用尝试调用包含此操作的 intent 时，系统会基于应用的目标 SDK 版本执行以下操作之一：

如果应用以 Android 12 或更高版本为目标平台，则会发生 SecurityException。
如果应用以 Android 11（API 级别 30）或更低版本为目标平台，则系统不会执行 intent，并且 Logcat 中会显示以下消息：

##### 10.系统会屏蔽穿透某些窗口的触摸操作
##### 11.在 Android 12 中，按下“返回”按钮时,现在系统会将 其任务根的启动器 activity 及其任务移到后台，而不是finish activity
当使用主屏幕按钮或手势从应用中导航出应用时，新行为与当前行为一致。
建议您使用 AndroidX Activity API 提供自定义返回导航
##### 12.以 Android 12 或更高版本为目标平台，系统会对来自某些移动传感器和位置传感器的数据的刷新率施加限制
##### 13.以 Android 12 或更高版本为目标平台，且包含使用 intent 过滤器的 activity、服务或广播接收器，您必须为这些应用组件显式声明 android:exported 属性。
##### 14.为了在支持双并发 Wi-Fi 网络的设备上提供更好的用户体验，我们建议所有应用（特别是触发点对点连接的应用）脱离调用 WifiManager.getConnectionInfo()，而改用 NetworkCallback.onCapabilitiesChanged()，以获取与用于注册 NetworkCallback 的 NetworkRequest 匹配的所有 WifiInfo 对象。从 Android 12 开始，弃用了 getConnectionInfo()。

##### 14.Android 12 引入了一种名为 Material You 的新设计语言
##### 15.Android 12 引入了 BLUETOOTH_SCAN、BLUETOOTH_ADVERTISE 和 BLUETOOTH_CONNECT 权限
##### 16.Android 12 针对使用 PackageInstaller API 的应用引入了 setRequireUserAction() 方法。此方法可让安装程序应用执行应用更新而无需用户确认操作


### Android 11 API 30

##### 1.从 Android 11 开始，使用分区存储模型的应用只能访问自身的应用专用缓存文件。
应用无法在外部存储设备上创建自己的应用专用目录。如需访问系统为您的应用提供的目录，请调用 getExternalFilesDirs()。不能访问其他任何应用的数据目录中的文件。应用无法再访问外部存储设备中的任何其他应用的专用于特定应用的目录中的文件。
存储运行时权限已重命名为文件和媒体。
WRITE_EXTERNAL_STORAGE 权限和 WRITE_MEDIA_STORAGE 特许权限将不再提供任何其他访问权限。
##### 2.前台服务类型 camera 和 microphone
如果您的应用在后台运行时启动了某项前台服务，则该前台服务无法访问麦克风或摄像头。此外，除非您的应用具有在后台访问位置信息的权限，否则该服务无法访问位置信息。
##### 3.在后台访问位置信息的权限：用户必须转到系统设置，才能向应用授予在后台访问位置信息的权限。

### Android 10 API 29 [文档](https://developer.android.com/about/versions/10/privacy/changes?hl=zh-cn)
##### 1.分区存储
##### 2.增强了用户对位置权限的控制力
仅限前台权限，可让用户更好地控制应用对设备位置信息的访问权限
##### 3.系统执行后台 Activity
针对从后台启动 Activity 实施了限制
##### 4.针对访问设备序列号和 IMEI 实施了限制
应用必须具有 READ_PRIVILEGED_PHONE_STATE 特许权限才能访问设备的不可重置标识符（包含 IMEI 和序列号。
系统会传输随机分配的 MAC 地址。
##### 5.外部存储访问权限范围限定为应用文件和媒体
##### 6.在后台运行时访问设备位置信息需要权限
Android 10 引入了 ACCESS_BACKGROUND_LOCATION 权限。

与 ACCESS_FINE_LOCATION 和 ACCESS_COARSE_LOCATION 权限不同，ACCESS_BACKGROUND_LOCATION 权限仅会影响应用在后台运行时对位置信息的访问权限。除非符合以下条件之一，否则应用将被视为在后台访问位置信息：

属于该应用的 Activity 可见。
该应用运行的某个前台设备已声明前台服务类型为 location。


### Android 9 API 28 [文档](https://developer.android.com/about/versions/pie/android-9.0-migration?hl=zh-cn#bfa)
##### 1.Android 9 限制后台应用访问用户输入和传感器数据的能力。 如果您的应用在运行 Android 9 设备的后台运行，系统将对您的应用采取以下限制：

您的应用不能访问麦克风或摄像头。
使用连续报告模式的传感器（例如加速度计和陀螺仪）不会接收事件。
使用变化或一次性报告模式的传感器不会接收事件。
如果您的应用需要在运行 Android 9 的设备上检测传感器事件，请使用前台服务。
##### 2.限制访问通话记录
Android 9 引入 CALL_LOG 权限组并将 READ_CALL_LOG、WRITE_CALL_LOG 和 PROCESS_OUTGOING_CALLS 权限移入该组。 在之前的 Android 版本中，这些权限位于 PHONE 权限组。

对于需要访问通话敏感信息（如读取通话记录和识别电话号码）的应用，该 CALL_LOG 权限组为用户提供了更好的控制和可见性。
在未首先获得 READ_CALL_LOG 权限的情况下，除了应用的用例需要的其他权限之外，运行于 Android 9 上的应用无法读取电话号码或手机状态
##### 3.想要使用前台服务的应用必须首先请求 FOREGROUND_SERVICE 权限。这是普通权限，因此，系统会自动为请求权限的应用授予此权限
##### 4.不允许直接通过路径访问其他应用的数据目录

##### 5.Android 9 支持最新的全面屏
其中包含为摄像头和扬声器预留空间的屏幕缺口。 通过 DisplayCutout 类可确定非功能区域的位置和形状，这些区域不应显示内容。 要确定这些屏幕缺口区域是否存在及其位置，请使用 getDisplayCutout() 函数。
#### 6.适用于可绘制对象和位图的 ImageDecoder
Android 9 引入了 ImageDecoder 类，可提供现代化的图像解码方法。 使用该类取代 BitmapFactory 和 BitmapFactory.Options API。

### Android 8.0 API 26-27 [文档](https://developer.android.com/about/versions/oreo/android-8.0-changes?hl=zh-cn#all-apps) [文档1](https://developer.android.com/about/versions/oreo/android-8.0?hl=zh-cn)
##### 1.系统会限制未在前台运行的应用的某些行为
现在，在后台运行的应用对后台服务的访问受到限制。
应用无法使用其清单注册大部分隐式广播（即，并非专门针对此应用的广播）。
即使应用在后台运行，系统也允许其调用 Context.startForegroundService()。不过，应用必须在创建服务后的五秒内调用该服务的 startForeground() 函数。
降低了后台应用接收位置更新的频率。
##### 2.WebView
如果您的应用的网络安全性配置选择退出对明文流量的支持，那么您的应用的 WebView 对象无法通过 HTTP 访问网站。每个 WebView 对象必须转而使用 HTTPS
##### 3.重新设计通知
引入了通知渠道;通知标志;通知超时
##### 4.JobScheduler 改进

##### 5.后台 Service 限制
系统可以区分前台和后台应用.如果满足以下任意条件，应用将被视为处于前台：

具有可见 Activity（不管该 Activity 已启动还是已暂停）。
具有前台 Service。
另一个前台应用已关联到该应用（不管是通过绑定到其中一个 Service，还是通过使用其中一个内容提供程序）。 例如，如果另一个应用绑定到该应用的 Service，那么该应用处于前台：
IME
壁纸 Service
通知侦听器
语音或文本 Service
在很多情况下，您的应用都可以使用 JobScheduler 作业替换后台 Service


### Android 7 API 24-25  [文档](https://developer.android.com/about/versions/nougat/android-7.0?hl=zh-cn)

##### 1.Android 7.0 将一项新的 3D 渲染 API Vulkan™ 集成到平台中
##### 2.Android 7.0 现在支持在平台中进行号码屏蔽，提供框架 API，让服务提供商可以维护屏蔽的号码列表
##### 3.Android 7.0 允许默认的手机应用过滤来电
##### 4.启用多进程 WebView
从 Android 7.0 中的 Chrome 版本 51 开始，WebView 将开发者选项“多进程 WebView”被启用时，在一个单独的沙盒进程中运行网页内容。
##### 5.想要在 WebView 中注入 Javascript 的开发者应在页面开始加载后执行脚本
##### 6.FileProvider在应用间共享文件

### Android 6 API   [文档](https://developer.android.com/about/versions/marshmallow/android-6.0-changes?hl=zh-cn)

##### 1.运行时权限
##### 2.低电耗模式和应用待机模式
设备会定期短时间恢复正常工作，以便进行应用同步，还可让系统执行任何挂起的操作
##### 3.硬件标识符访问权
对于使用 WLAN API 和 Bluetooth API 的应用，Android 移除了对设备本地硬件标识符的编程访问权。WifiInfo.getMacAddress() 方法和 BluetoothAdapter.getAddress() 方法现在会返回常量值 02:00:00:00:00:00。

##### 4.音频管理器变更
setStreamSolo() 方法已弃用，您应该改为调用 requestAudioFocus() 方法。类似地，setStreamMute() 方法也已弃用，请改为调用 adjustStreamVolume() 方法并传入方向值 ADJUST_MUTE 或 ADJUST_UNMUTE。


### Android 5 API  (https://developer.android.com/about/versions/android-5.0?hl=zh-cn)
##### 1.Android 5.0 新增了一个 JobScheduler API，允许您定义一些系统在稍后或指定条件下（如设备充电时）以异步方式运行的作业，从而优化电池寿命
