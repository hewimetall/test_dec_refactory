# Проект реализации decimal из школы 21
    > Проект выполнен в виде моделей реализованных как библиотеки. 
## Структура проекта
- binary: реализация бинарных операция над decimal для целочисленного представления.
    * logic: ^ | &
    * shift: left, rith
    * binary oper: add(+), mul(*),sub(-), cel(/)
    * helpers: pow, normolize, comparison, get_bit, set_bit, max, min, zerro_data, int64_to_decimal
    > Зависимости: Нет
    > Coverage: 
- comparison: реализует сравнения для типа decimal.
    > Зависимости: binary
    > Coverage: 
- conversion: реализует конвертацию типа.
    > Зависимости: binary
    > Coverage: 
- helpers: содержит набор вспомогательных функция
    > Зависимости: binary comparison math conversion
    > Coverage: 
- math: реализует операторы `+, -, *, /` для типа decimal. 
    > Зависимости: binary comparison
    > Coverage: 


## Сборка проекта с использованием Makefile:
-  Проект разбит на несколько makefile
    * make_libs: содержит точки сборки библиотек
    * make_test: содержит точки сборки тестов
    * Makefile: главный файл.