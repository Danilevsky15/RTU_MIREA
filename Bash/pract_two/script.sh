#!/bin/bash

task1() {
  echo "
  Задача 1. Вывести служебную информацию о пакете matplotlib (Python). Разобрать основные элементы содержимого файла со служебной информацией из пакета. Как получить пакет без менеджера пакетов, прямо из репозитория?"
    pip show matplotlib
    echo "
    загрузка пакетов:"
    wget https://github.com/matplotlib/matplotlib/archive/refs/tags/v3.5.2.tar.gz
    echo "
  архив matplotlib загружен - распакуйте его с помощью команды tar:"
    echo "
  tar -xvzf v3.5.2.tar.gz"
}

task2() {
    echo "
    получение служебной информации о пакете express"
    npm view express

    echo "
    загрузка пакета express без менеджера пакетов:"
    wget https://github.com/expressjs/express/archive/refs/tags/4.18.2.tar.gz
    echo "
    архив express загружен = распакуйте его с помощью команды tar:"
    echo "
    tar -xvzf 4.18.2.tar.gz"
}

task3() {
    if ! command -v dot &> /dev/null; then
        echo "
        graphviz- не установлен - установите graphviz для продолжения"
        echo "
        для установки используйте команду - sudo apt install graphviz"
        return
    fi

    echo "
    генерация зависимостей matplotlib"

    pip install pipdeptree

    pipdeptree --graph-output dot > matplotlib_dependencies.dot
    echo "
    файл matplotlib_dependencies.dot с зависимостями создан"

    dot -Tpng matplotlib_dependencies.dot -o matplotlib_dependencies.png
    echo "
    изображение matplotlib_dependencies.png создано"

    echo "
    ненерация зависимостей express"

    npm ls --json > express_dependencies.json

    echo 'digraph express_dependencies {' > express_dependencies.dot
    jq -r '.dependencies | to_entries[] | .key as $pkg | .value.dependencies | to_entries[] | "  \"" + $pkg + "\" -> \"" + .key + "\";"' express_dependencies.json >> express_dependencies.dot
    echo '}' >> express_dependencies.dot

    dot -Tpng express_dependencies.dot -o express_dependencies.png
    echo "изображение express_dependencies.png создано."
}

while true; do
    echo "
    выберите задание (от 1 до 6) или введите 'exit' для выхода:"
    read -r choice

    case $choice in
        1)
            task1
            ;;
        2)
            task2
            ;;
        3)
            task3
            ;;
        4)
            task4
            ;;
        5)
            task5 "$2"
            ;;
        6)
            task6
            ;;
        exit)
            echo "
    эх...печально:("
            break
            ;;
        *)
            echo "
    неверный выбор. введите число от 1 до 6 или 'exit' для выхода."
            ;;
    esac
done
