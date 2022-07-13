# Драйвер RGB led панели 64x32 на основе чипа lyd6126 (возможно аналог FM6126)

В данном репозитории размещен скетч для ардуино (нано), но код можно легко портировать и на другие платформы (старался избегать функций, свойственных Arduino IDE, дабы облегчить портирование).
Данный скетч - версия с кодировкой цвета пикселей в 3х битах (8 цветов), регулировка яркости производится сразу всей панели.
main-stm8.c - для STM8, STVD Cosmic.
lyd6126-icn2012-64X32 - для STM32, stm32CubeIDE.
Массив RAW_DISPLAY представляет собой массив цветов для каждого пикселя.
Подготовкой массива цветов соответствующих пикселей занимается img_to_raw_rgb3.py. После преобразования изображения создается файл *.*.raw_rgb3 для вставки последовательности в скетч (uint8_t RAW_DISPLAY[3][256] = {*raw_rgb3*};).  
<p align="center" width="100%">
    <img width="100%" src="https://github.com/AlexanderChad/lyd6126-icn2012-64X32/blob/main/img_test/IMG_20210930.gif" alt="test" title="регулировка яркости">
</p>
<p align="center" width="100%">
    <img width="100%" src="https://github.com/AlexanderChad/lyd6126-icn2012-64X32/blob/main/img_test/IMG_20210930_185018.jpg" alt="test" title="test1">
</p>  
<p align="center" width="100%">
    <img width="100%" src="https://github.com/AlexanderChad/lyd6126-icn2012-64X32/blob/main/img_test/IMG_20211028_141812.jpg" alt="test" title="Ray Poward">
</p>
