fun String.isValidCCNumber(): Boolean {
    val sanitized = this.filter { it.isDigit() }

    if (sanitized.isEmpty()) return false

    val digits = sanitized.reversed().map { it.toString().toInt() }

    val sum = digits.mapIndexed { index, digit ->
        if (index % 2 == 1) {
            val doubled = digit * 2
            if (doubled > 9) doubled - 9 else doubled
        } else {
            digit
        }
    }.sum()

    return sum % 10 == 0
}


Задание: 
Для проверки корректности номера банковских карт используется алгоритм Луна. Реализуйте функцию расширения `isValidCCNumber(): Boolean` для класса `String` с использованием этого алгоритма. Все символы, не являющиеся цифрами (в т.ч. пробелы) игнорируются.

Цифры проверяемой последовательности нумеруются справа налево.
Цифры, оказавшиеся на нечётных местах, остаются без изменений.
Цифры, стоящие на чётных местах, умножаются на 2.
Если в результате такого умножения возникает число больше 9, оно заменяется суммой цифр получившегося произведения — однозначным числом, то есть цифрой.
Все полученные в результате преобразования цифры складываются. Если сумма кратна 10, то исходные данные верны.
Пример корректного номера карты: "4561 2612 1234 5467"
