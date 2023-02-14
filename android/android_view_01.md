## Android的触摸事件以及View的布局、绘制流程

### 1. 触摸事件分发
```
Activity.dispatchTouchEvent{
        onUserInteraction()；
        1-getWindow().superDispatchTouchEvent{
            //发给根ViewGroup
            ViewGroup.dispatchTouchEvent{
                    1-onFilterTouchEventForSecurity()//是否过滤此次事件
                    2-onInterceptTouchEvent()//如果是 ACTION_DOWN,并且允许拦截
                    3-dispatchTransformedTouchEvent() //如果上一步没拦截，则分发给子View {
                        View.dispatchTouchEvent{
                                1-onFilterTouchEventForSecurity()//检查是否要过滤掉
                                2-OnTouchListener.onTouch(）//如果设置了OnTouchListener
                                3-onTouchEvent()//如果OnTouchListener没消费此事件 {
                                   // 如果设置了 点击委托 TouchDelegate，它可以处理view区域外的事件。
                                   // 如果返回true，则会消费掉事件，打断后续的点击、长按等逻辑
                                        mTouchDelegate.onTouchEvent(){
                                            委托的View.dispatchTouchEvent()
                                        }
                                    }
                               }
                    }
                    4-OnTouchListener.onTouch(）//如果子View没消费此事件，如果设置了OnTouchListener
                    5-onTouchEvent()//如果子View、OnTouchListener都没消费此事件
                }
        }
        2- onTouchEvent() 如果未消费此事件；
}
```
2.View的测量、绘制 https://blog.yorek.xyz/android/framework/View%E7%9A%84%E7%BB%98%E5%88%B6%E5%8E%9F%E7%90%86/#21-measurespec
计算宽高 --> 布局位置  -->绘制
```
ViewGroup.onMeasure(){
        View.onMeasure()//遍历子View
}

ViewGroup.onLayout(){
        View.layout() //遍历子View {
                onLayout()
        }
}

ViewGroup.draw(){
        drawBackground();//如果有背景
        onDraw();/如果有背景
        dispatchDraw(){
            drawChild(){
                View.draw(){
                    drawBackground()
                    onDraw()
                    onDrawForeground()
                    drawDefaultFocusHighlight()
                }
            }
        }
}


```