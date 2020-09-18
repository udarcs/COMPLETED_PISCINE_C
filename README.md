# 「 Completed Tasks of the Piscine C 」

 • Этот репозиторий содержит множество версий выполненных задач на каждый день самого первого бассейна по Си. 


 • На данный момент выполнена работа по проверке заданий на корректную работоспособность у папки `Exam_C`, `Rush00`, `Rush01` и папок от d00 до d12 включительно.


 • Каждая папка каждого `дня бассейна` содержит pdf файл с заданиями написанные на английском либо французском языке. 


 • Также, в самих папках каждого `дня бассейна` будут подпапки содержащие в себе одиночный файл(или группу файлов) с требуемым названием, хранящие внутри себя несколько версий выполения требуемого задния. Эти версии выполнения задания в файле будут разделены между собой тройной строкой комментария. 


 • Если задание требует содержать в себе несколько файлов(такие задания будут ближе к концу), то версии его выполнения будут разделены по подпапкам.
 
 Например: 
 
      "./d10/ex06/Solution_00/",
      "./d10/ex06/Solution_01/",
      "./d10/ex06/Solution_02/",
      и т.д.


 • Так же в папке выполненого задания может содержаться тестовый файл или папка с тестовыми файлами, скомпилировав которые можно посмотреть как работает требуемая в заданиии функция(или несколько функций).



## Компиляция:

Если кратко, то компиляция - это процесс трансляции файла с исходным кодом на языке Си в машинный код, который будет понятен для центрального процессора. Это нужно для того чтобы мы могли запустить нашу программу и она, с помощь центрального процессора, могла выполнить запрограммированные нами действия.

Для компиляции нашей программы вначале перейдем в папку содержащую файл с написанным нами исходным кодом этой программы. Откройте окно терминала и с помощью команды `cd` и `адреса до папки` содержащей файл с исходным кодом перейдите в папку где он находится(допустим у меня он лежит в папке `Документы`): 

      cd ~/Документы


Что бы скомпилировать, к примеру, файл `test.c` содержащий написанный напи исходный код программы нужно:
 * Написать в терминале `имя программы-компилятора`(с помощью которого вы будете перобразовывать наш файл с текстовыми инструкциями в машинный код понятный процессору).
 * Добавить `параметры компиляции` 
 * И указать `путь до файла` содержащего исходный код нашей программмы(т.к. мы уже находимся в дериктории с этим файлом то адрес до файла мы запишем вот так `test.c` ). 


В итоге у вас должна получиться вот такая команда для компиляции файла с исходным кодом(на языке Cи) в исполняемый файл понятный процессору : 

      gcc -Wall -Werror -Wextra test.c 


Далее нажимаем Enter и на выходе(если у вас система семейства `unix`) получим файл `a.out`. Если же у вас система `windows` то на выходе вы получите файл `a.exe`. 

Исполняемый файл программы появится в той дерриктории, в которую вы перешли в через окно терминала перед компиляцией(в котором компилировали файл с исходным кодом).



## Особенности запуска полученой программы:

Если у вас `Windows` запустить программму можно просто написав в окне терминала путь к ней :

      ./a.exe

Но если у вас `Linux` или др операционная система семейства `Unix`, то для того чтобы система позволила вам запустить исполняемый файл с созданной вами программой, перед запуском необходимо дать этому исполняемому файлу права на выполнение! Иначе, система не позволит его запустить. 

По этому дадим нашему `исполняемому файлу` права на выполнение, вот такой командой, прописав в терминале < *имя программы* >, < *аргументы выполения* > и < *путь до файла* >: 

      chmod +x ./a.out

 Чтобы запустить программу через терминал напишите в окне терминала путь к ней: 

      ./a.out



> ### *LifeHack*:
> 
> Чтобы не терять время, можно все команды соединить в одну строку записав в окне терминала вот так:
> 
      gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out



## Карта Бассейна по Си:

![map_Piscine_C](map_of_Piscine_C.png)





