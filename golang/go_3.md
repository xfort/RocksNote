### Go函数传参，值传递？引用传递？

传值的意思是：函数传递的总是原来这个东西的一个副本，一副拷贝。
go都是值传递，即使是指针类型，传递的是指针的一个副本

Go语言(Golang)是没有引用传递的

map、chan、slice为引用类型，但引用类型不是传引用

Go语言中所有的传参都是值传递（传值），都是一个副本，一个拷贝。
因为拷贝的内容有时候是非引用类型（int、string、struct等这些），这样就在函数中就无法修改原内容数据；
有的是引用类型（指针、map、slice、chan等这些），这样就可以修改原内容数据。

是否可以修改原内容数据，和传值、传引用没有必然的关系。
在C++中，传引用肯定是可以修改原内容数据的，在Go语言里，虽然只有传值，但是我们也可以修改原内容数据，因为参数是引用类型。

这里也要记住，引用类型和传引用是两个概念。
```
func main() {
	i:=19
	p:=Person{name:"张三",age:&i}
	fmt.Println(p)
	modify(p)
	fmt.Println(p)
}

type Person struct {
	name string
	age  *int
}

func (p Person) String() string{
	return "姓名为：" + p.name + ",年龄为："+ strconv.Itoa(*p.age)
}

func modify(p Person){
	p.name = "李四"
	*p.age = 20
}
```