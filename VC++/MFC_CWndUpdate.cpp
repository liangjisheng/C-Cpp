MFC中窗口刷新函数详解

Invalidate在消息队列中加入一条WM_PAINT消息，其无效区为整个客户区。而UpdateWindow
直接发送一个WM_PAINT消息，其无效区范围就是消息队列中WM_PAINT消息（最多只有一条）
的无效区。效果很明显，调用Invalidate之后，屏幕不一定马上更新，因为WM_PAINT消息
不一定在队列头部，而调用UpdateWindow会使WM_PAINT消息马上执行的，绕过了消息队列。
如果你调用Invalidate之后想马上更新屏幕，那就加上UpdateWindow()这条语句。

Invalidate():该函数的作用是使整个窗口客户区无效
MFC为窗口类提供了WM_PAINT的消息处理函数OnPaint，OnPaint负责重绘窗口。视图类有一
些例外，在视图类的OnPaint函数中调用了OnDraw函数，实际的重绘工作由OnDraw来完成。
参数bErase为TRUE时，重绘区域内的背景将被擦除，否则，背景将保持不变。

InvalidateRect():
该函数的功能与Invalidate基本一样，不同的是，它是使指定的某个区域无效，需要输
入一个区域，如果参数为NULL，则设置整个窗口为无效区。
	
UpdateWindow():
UpdateWindow( )的作用是使窗口立即重绘。调用Invalidate等函数后窗口不会立即重绘，
这是由于WM_PAINT消息的优先级很低，它需要等消息队列中的其它消息发送完后才能被处理。
调用UpdateWindow函数可使WM_PAINT被直接发送到目标窗口，从而导致窗口立即重绘

如果不调用 InvalidateRect就调用 UpdateWindow，那么UpdateWindow什么都不做。 
如果调用 InvalidateRect 后不调用UpdateWindow，则系统会自动在窗口消息队列为空的
时候，系统自动发送一WM_PAINT消息。 
调用UpdateWindow()时将会发送一个WM_PAINT消息，而应用程序在接收到WM_PAINT消息后，
将自动地调用Invalidate()

updateWindow要求系统对区域进行立即重绘，其只对声明为无效的区域起作用，
而Invalidate()是声明无效区域的方式之一
Invalidat最后也是调用InvalidatRect。

当需要更新或者重绘窗口时，一般系统会发出两个消息WM_PAINT(通知客户区有变化)
和WM_NCPAINT(通知非客户区有变化)WM_NVPAINT系统会自己搞定WM_PAINT消息对应的
函数是OnPaint(),它是系统默认的接受WM_PAINT消息的函数，但我们一般在程序中做
重绘时都在OnDraw函数中进行的，因为在视图类ONPAINT函数中调用了ONDRAW函数。

上面讲到InvalidateRect(&Rect) 和 Invalidate()。两个函数形式和功能差不多，但
Invalidate是使得整个窗口形成无效矩形，而InvalidateRect(&Rect)是使得指定的区域
无效。Invalidate()申明无效，等待WM_PAINT消息以便重绘，队列中无其他消息时系统会
自动发送。而UpdateWindow()会立即发送WM_PAINT，不过在它发送前，先调用
GetUpdateRect(hWnd,NULL,TRUE)看有无可绘制区域，如果没有则不发送消息。
RedrawWindow()RedrawWindow()则是具有Invalidate()和UpdateWindow()的双特性。
声明窗口的状态为无效，并立即更新窗口，立即调用WM_PAINT消息处理。   

系统为什么不在调用Invalidate时发送WM_PAINT消息呢？又为什么非要等应用消息队列
为空时才发送WM_PAINT消息呢？这是因为系统把在窗口中的绘制操作当作一种低优先级
的操作，于是尽可能地推后做。不过这样也有利于提高绘制的效率：两个WM_PAINT消息
之间通过InvalidateRect和InvaliateRgn使之失效的区域就会被累加起来，然后在一个
WM_PAINT消息中一次得到更新，不仅能避免多次重复地更新同一区域，也优化了应用的
更新操作。像这种通过InvalidateRect和InvalidateRgn来使窗口区域无效，依赖于系统
在合适的时机发送WM_PAINT消息的机制实际上是一种异步工作方式，也就是说，在无效
化窗口区域和发送WM_PAINT消息之间是有延迟的；有时候这种延迟并不是我们希望的，
这时我们当然可以在无效化窗口区域后利用SendMessage 发送一条WM_PAINT消息来强制
立即重画，但不如使用Windows GDI为我们提供的更方便和强大的函数：      
    
UpdateWindow和RedrawWindow。UpdateWindow会检查窗口的Update Region，当其不为空
时才发送WM_PAINT消息；RedrawWindow则给我们更多的控制：是否重画非客户区和背景，
是否总是发送 WM_PAINT消息而不管Update Region是否为空等。BeginPaint和WM_PAINT
消息紧密相关。试一试在WM_PAINT处理函数中不写BeginPaint会怎样？程序会像进入了
一个死循环一样达到惊人的CPU占用率，你会发现程序总在处理一个接一个的WM_PAINT
消息。这是因为在通常情况下，当应用收到WM_PAINT消息时，窗口的Update Region都
是非空的（如果为空就不需要发送WM_PAINT消息了），BeginPaint的一个作用就是把该
Update Region置为空，这样如果不调用BeginPaint，窗口的Update Region就一直不为空，
如前所述，系统就会一直发送WM_PAINT消息。 BeginPaint和WM_ERASEBKGND消息也有关系。
当窗口的Update Region被标志为需要擦除背景时，BeginPaint会发送WM_ERASEBKGND消息
来重画背景，同时在其返回信息里有一个标志表明窗口背景是否被重画过。当我们用
InvalidateRect和InvalidateRgn来把指定区域加到Update Region中时，可以设置该区域
是否需要被擦除背景，这样下一个BeginPaint就知道是否需要发送WM_ERASEBKGND消息了。
另外要注意的一点是，BeginPaint只能在WM_PAINT处理函数中使用