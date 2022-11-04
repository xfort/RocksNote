## Golang
* [官网](https://golang.org/)
* [官网中国](https://golang.google.cn/)
* [Install](https://golang.org/doc/install)
* [Go入门指南](https://github.com/unknwon/the-way-to-go_ZH_CN/blob/master/eBook/directory.md)
* [Go Web编程](https://github.com/astaxie/build-web-application-with-golang/blob/master/zh/preface.md)
* [基础教程](https://github.com/chai2010/advanced-go-programming-book/blob/master/SUMMARY.md)

#### 1.环境变量
* GOROOT 表示 Go 在你的电脑上的安装位置
* GOBIN 表示编译器和链接器的安装位置，默认是 $GOROOT/bin
* GOPATH 可以包含多个工作目录，多个目录的时候Windows是分号，Linux系统是冒号，当有多个GOPATH时，默认会将go get的内容放在第一个目录下
* GOPROXY 默认 https://proxy.golang.org
```
go env -w GOPROXY=https://goproxy.cn,direct  //改为国内proxy
src 存放源代码（比如：.go .c .h .s等）
pkg 编译后生成的文件（比如：.a）
bin 编译后生成的可执行文件（为了方便，可以把此目录加入到 $PATH 变量中，如果有多个gopath，那么使用${GOPATH//://bin:}/bin添加所有的bin目录）
```
#### 2. Go Module
要启用go module支持首先要设置环境变量<code>GO111MODULE</code>，通过它可以开启或关闭模块支持，它有三个可选值：<code>off</code>、<code>on</code>、<code>auto</code>，默认值是<code>auto</code>
```
 go mod init  \\初始化go.mod
 go mod tidy \\以确保module文件是最新且准确的
```
#### 3.项目结构 [参考标准](https://github.com/golang-standards/project-layout)
##### /cmd
本项目的主干。
每个应用程序的目录名应该与你想要的可执行文件的名称相匹配(例如，/cmd/myapp)。
不要在这个目录中放置太多代码。如果你认为代码可以导入并在其他项目中使用，那么它应该位于 /pkg 目录中。如果代码不是可重用的，或者你不希望其他人重用它，请将该代码放到 /internal 目录中。你会惊讶于别人会怎么做，所以要明确你的意图!
通常有一个小的 main 函数，从 /internal 和 /pkg 目录导入和调用代码，除此之外没有别的东西。
##### /internal
私有应用程序和库代码。这是你不希望其他人在其应用程序或库中导入代码。请注意，这个布局模式是由 Go 编译器本身执行的。有关更多细节，请参阅Go 1.4 release notes 。注意，你并不局限于顶级 internal 目录。在项目树的任何级别上都可以有多个内部目录。
你可以选择向 internal 包中添加一些额外的结构，以分隔共享和非共享的内部代码。这不是必需的(特别是对于较小的项目)，但是最好有有可视化的线索来显示预期的包的用途。你的实际应用程序代码可以放在 /internal/app 目录下(例如 /internal/app/myapp)，这些应用程序共享的代码可以放在 /internal/pkg 目录下(例如 /internal/pkg/myprivlib)。
##### /pkg
外部应用程序可以使用的库代码(例如 /pkg/mypubliclib)。其他项目会导入这些库，希望它们能正常工作，所以在这里放东西之前要三思:-)注意，internal 目录是确保私有包不可导入的更好方法，因为它是由 Go 强制执行的。/pkg 目录仍然是一种很好的方式，可以显式地表示该目录中的代码对于其他人来说是安全使用的好方法
##### /vendor
应用程序依赖项(手动管理或使用你喜欢的依赖项管理工具，如新的内置 Go Modules 功能)。go mod vendor 命令将为你创建 /vendor 目录。请注意，如果未使用默认情况下处于启用状态的 Go 1.14，则可能需要在 go build 命令中添加 -mod=vendor 标志。
##### /api 服务应用程序目录
OpenAPI/Swagger 规范，JSON 模式文件，协议定义文件。
##### /web Web 应用程序目录
特定于 Web 应用程序的组件:静态 Web 资产、服务器端模板和 SPAs
##### /configs
配置文件模板或默认配置
##### /scripts
执行各种构建、安装、分析等操作的脚本。
这些脚本保持了根级别的 Makefile 变得小而简单
##### /build
打包和持续集成。
将你的云( AMI )、容器( Docker )、操作系统( deb、rpm、pkg )包配置和脚本放在 /build/package 目录下。
将你的 CI (travis、circle、drone)配置和脚本放在 /build/ci 目录中。请注意，有些 CI 工具(例如 Travis CI)对配置文件的位置非常挑剔。尝试将配置文件放在 /build/ci 目录中，将它们链接到 CI 工具期望它们的位置(如果可能的话)。
##### /tools
这个项目的支持工具。注意，这些工具可以从 /pkg 和 /internal 目录导入代码。
##### /examples
你的应用程序和/或公共库的示例。
