#include "stm32f10x.h"    // Device header
//PINLERIN CIKIS OLARAK KULLANILIP LED YAKMA
void GpioConfig(){
	//mod hiz ve hangi led aticagimizi belirliyecegiz 
	GPIO_InitTypeDef GPIOInitStructure;
	//portlar kapali gelmekte bunlari aktif etmeliyiz 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	//sag tik parametreye go yapip hangi portlar bagli gorebiliriz.
GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//BUNU ISLETIM  SISTEMINE BILDIRMEMIZ LAZIM
	GPIO_Init(GPIOB,&GPIOInitStructure);
}

void delay(uint32_t time){
	
	while(time--);

}

int main(){
	GpioConfig();
	
while(1){
	GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_SET);
		delay(3600000);
		GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_RESET);
		delay(3600000);
}	
	
	
	
	
	
	
}