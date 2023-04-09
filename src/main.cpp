/*
接线说明:
(单片机为esp32s3,tft屏幕的驱动芯片为ST7735S)

sck(SCL) =Pin(18)
mosi（SDA）=Pin(17)
dc = Pin(6)
cs = Pin(14)
rst（RES）= Pin(9)
BL--不接(控制屏幕背光的,可以不接)


程序说明:
本程序能够显示图片,
最好是显示图片的大小能够与TFT屏幕大小一致,本例采用的TFT屏幕大小为128*160


注意事项:
1:使用TFT_eSPI这个库时要先修改 User_Setup.h 中的关于TFT屏幕的相关设置,修改屏幕对应的驱动芯片及对应的各接口的IO口
2:我将要显示的图片及将转换的文件放在了picture文件夹中
3:在文件一开始引入图片文件 #include "../picture/picture.h"即可使用
4:使用时先将找到的图片转换为 PNG格式(我不知道是否为必须,好像不是,JPG也可以),再通过ImageConverter565这个软件将图片转化为.C文件,在将此文件转换为.h文件,最后在main.c文件中引入即可使用


作者:灵首

时间:2023_3_8


*/


#include <Arduino.h>
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include "../picture/p1.h"
#include "../picture/p2.h"
#include "../picture/p3.h"
#include "../picture/p4.h"
#include "../picture/p5.h"
#include "../picture/p6.h"
#include "../picture/p7.h"



TFT_eSPI tft = TFT_eSPI(128,160);  // 调用库，在User Setup.h中定义引脚

void setup() 
{
  Serial.begin(115200);
  tft.init();   //初始化
  //tft.fillScreen(TFT_WHITE);      //设置背景颜色
  tft.setSwapBytes(true);       //这一步很关键的,是把RGB换做BGR,没有这一步图像会花,加上这一句才能正确显示图像
  //tft.pushImage(0,0,128,160,p2);  //放置图片,并设置图片位置   

  // put your setup code here, to run once:
}

void loop() 
{
  tft.pushImage(0,0,128,160,p1);
  delay(2000);
  tft.pushImage(0,0,128,160,p2);
  delay(2000);
  tft.pushImage(0,0,128,160,p3);
  delay(2000);
  tft.pushImage(0,0,128,160,p4);
  delay(2000);
  tft.pushImage(0,0,128,160,p5);
  delay(2000);
  tft.pushImage(0,0,128,160,p6);
  delay(2000);
  tft.pushImage(0,0,128,160,p7);
  delay(2000);
  // put your main code here, to run repeatedly:
  Serial.println("change!!!");
}