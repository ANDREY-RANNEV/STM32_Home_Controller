// A0 A1 подключены термисторы - 2 канала температуры
// A2 с потенцометра просто напряжение
//
// SDA -> A4
// SCL -> A5
// I2C device found at address 0x3C OLED SH1106 дисплей 128Х64
/*
D7 А линия валкодера
D6 B Линия валкодера
D5 кнопка 1
D4 Кнопка 2
D3 выход на MOSFET1
D2 кнопка 3 
D11 выход mosfet2

1 	0x0000 	RESET 	Вектор сброса 	
2 	0x0002 	INT0 	Внешнее прерывание 0 	INT0_vect
3 	0x0004 	INT1 	Внешнее прерывание 1 	INT1_vect
4 	0x0006 	PCINT0 	Прерывание 0 по изменению состояния выводов 	PCINT0_vect
5 	0x0008 	PCINT1 	Прерывание 1 по изменению состояния выводов 	PCINT1_vect
6 	0x000A 	PCINT2 	Прерывание 2 по изменению состояния выводов 	PCINT2_vect
7 	0x000C 	WDT 	Таймаут сторожевого таймера 	WDT_vect
8 	0x000E 	TIMER2_COMPA 	Совпадение A таймера/счетчика T2 	TIMER2_COMPA_vect
9 	0x0010 	TIMER2_COMPB 	Совпадение B таймера/счетчика T2 	TIMER2_COMPB_vect
10 	0x0012 	TIMER2_OVF 	Переполнение таймера/счетчика T2 	TIMER2_OVF_vect
11 	0x0014 	TIMER1_CAPT 	Захват таймера/счетчика T1 	TIMER1_CAPT_vect
12 	0x0016 	TIMER1_COMPA 	Совпадение A таймера/счетчика T1 	TIMER1_COMPA_vect
13 	0x0018 	TIMER1_COMPB 	Совпадение B таймера/счетчика T1 	TIMER1_COMPB_vect
14 	0x001A 	TIMER1_OVF 	Переполнение таймера/счетчика T1 	TIMER1_OVF_vect
15 	0x001C 	TIMER0_COMPA 	Совпадение A таймера/счетчика T0 	TIMER0_COMPA_vect
16 	0x001E 	TIMER0_COMPB 	Совпадение B таймера/счетчика T0 	TIMER0_COMPB_vect
17 	0x0020 	TIMER0_OVF 	Переполнение таймера/счетчика T0 	TIMER0_OVF_vect
18 	0x0022 	SPI STC 	Передача по SPI завершена 	SPI_STC_vect
19 	0x0024 	USART_RX 	USART прием завершен 	USART_RX_vect
20 	0x0026 	USART_UDRE 	Регистр данных USART пуст 	USART_UDRE_vect
21 	0x0028 	USART_TX 	USART передача завершена 	USART_TX_vect
22 	0x002A 	ADC 	Преобразование АЦП завершено 	ADC_vect
23 	0x002C 	EE READY 	Готовность EEPROM 	EE_READY_vect
24 	0x002E 	ANALOG COMP 	Прерывание от аналогового компаратора 	ANALOG_COMP_vect
25 	0x0030 	TWI 	Прерывание от модуля TWI (I2C) 	TWI_vect
26 	0x0032 	SPM READY 	Готовность SPM 	SPM_READY_vect

Прерывания при изменении состояния вывода (Pin Change Interrupts, PCINT)
Для Ардуино УНО (и других плат на базе ATmega328/P) эти выводы:

    D8 .. D13 - генерируют запрос прерывания PCINT0
    A0 .. A5 - генерируют запрос прерывания PCINT1
    D0 .. D7 - генерируют запрос прерывания PCINT2

*/