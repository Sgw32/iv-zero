# IV-Zero Indicators

## Description

This project involves the use of IV-Indicators in the Zero version, which come in three types:

1. **Battery voltage meters**:  
   - In this case, the input is combined with KL15.

2. **Oil temperature meters**:  
   - The sensor is connected to the input, with the other end grounded.

3. **Oil pressure meters** (currently not in production):  
   - The sensor is connected between "Input" and "Ground."

These types of indicators consist of two boards: the main board and the display board.

## Connection

The connection is made to vehicles like Golf 2, Jetta 2, and others with a similar dashboard. Audi 80 compatibility may be available in the future.

## Electronic Components

The indicators are based on the Atmega48 chip with a minimalistic firmware installed. A modular DC/DC converter from 12V to 5V is used at the input, compatible with the well-known 7805 regulator in terms of pinout.

The display is implemented using 12 LEDs with brightness fixed by the firmware.

## Sensors Used

1. **For voltmeters**:  
   - Sensors are not required.

2. **For temperature meters**:  
   - VAG sensors - Ossca 01176 are used.

3. **For oil pressure meters**:  
   - Sensors similar to Digifiz Mini: [03C906051A](https://shop.digifizmini.de/en/sensors/68-pressure-sensor-03c906051a.html) are used.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contact

For more information or questions, contact us at Instagram [https://instagram.com/phol_labs](https://instagram.com/phol_labs).

# Индикаторы IV-Zero

## Описание

Это репозиторий проекта индикаторов IV Indicators в версии Zero, которые бывают трёх типов:

1. **Измерители напряжения батареи**:  
   - В этом случае вход объединяется с KL15.

2. **Измерители температуры масла**:  
   - Датчик подключается к входу, а его второй вывод к массе.

3. **Измерители давления масла** (в настоящее время не производятся):  
   - Датчик подключается между «Входом» и «Массой».

Индикаторы данного типа состоят из двух плат: основной платы и платы индикации.

## Подключение

Подключение осуществляется к автомобилям Golf 2, Jetta 2 и другим с аналогичной торпедой. Возможность подключения к Audi 80 может появиться в будущем.

## Электронные компоненты

Индикаторы работают на базе чипа Atmega48 с установленной минималистичной прошивкой. На входе используется DC/DC преобразователь модульного типа из 12В в 5В, совместимый по распиновке с известным стабилизатором 7805.

Индикация осуществляется при помощи 12 светодиодов с фиксированной яркостью, которая задается прошивкой.

## Применяемые датчики

1. **Для вольтметров**:  
   - Датчики не требуются.

2. **Для измерителей температуры**:  
   - Используются датчики VAG - Ossca 01176.

3. **Для датчиков давления масла**:  
   - Используются датчики, аналогичные Digifiz Mini: [03C906051A](https://shop.digifizmini.de/en/sensors/68-pressure-sensor-03c906051a.html).

## Лицензия

Этот проект распространяется под лицензией MIT. Подробности см. в файле LICENSE.

## Контакты

Для получения дополнительной информации и вопросов обращайтесь в ВК: [https://vk.com/sgw32](https://vk.com/sgw32).

---
