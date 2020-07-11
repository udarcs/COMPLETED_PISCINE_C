# Completed_Tasks_of_the_Piscine_C
##############################################################################################

 • Этот репозиторий содержит множество версий выполненных задач на каждый день самого первого басейна по Си. 



 • На данный момент выполнена работа по проверке заданий на корректную работоспособность у папки "Exam_C", "Rush00", "Rush01" и папок от d00 до d11 включительно.



 • Каждая папка каждого дня содержит pdf файл с заданиями написаные на английском либо французском языке. 



 • Также, каждая папка каждого дня содержит папку с заданием(например(./d03/ex00/)), в которой содержит одиночный файл(или группа файлов) с требуемым названием, а внутри этого файла будут находиться несколько версий выполения этого задания, которые разделены между собой тройной строкой комментария. 




 • Если задание требует содержать в себе несколько файлов(такие задания будут ближе к концу) то тогда версии его выполнения будут разделены по папкам. 




 • Так же папка задания будет содержать тестовый файл или папку с тестовыми файлами, скомпилировав которые можно запустить получившуюся программу и увидеть то как работает требуемая в заданиии функция(или нескотлько функций).

##############################################################################################

Что бы скомпилировать файл "test.c" откройте окно терминала и перейдите в папку где находится этот файл (допустим у меня он лежит в папке Документы): 

      cd ~/Документы


Далее напишите в окне терминала имя программы компилятора(с помощью которого вы будете перобразовывать наш файл с текстовыми инструкциями в машинный код понятный процессору).


После имени программы компилятора напишите параметры компиляции и путь до файла(у нас он будет в дериктории в которой мы уже находимся так что мы адрес запишем так "./test.c" ). 


В терминале у вас должна получиться вот такая команда для компиляции файла с исходным кодом на языке Cи в исполняемый файл :  

      gcc -Wall -Werror -Wextra test.c 


Далее нажимаем Enter и на выходе получим файл "a.out"(если у вас unix система) или файл "a.exe"(если у вас система windows). 


Выходной файл с программой появиться в той дерриктории, в которую вы сейчас перешли в через окно терминала в котором компилировали файл с кодом.


Если у вас Windows запустить программму можно просто написав в окне терминала путь к ней (./a.exe)


Если у вас Linux или др операционная система семейства Unix то перед запуском необходимо дать файлу права на выполнение, чтобы скомпилированная вами программа запустилась, иначе запустить ее не позволит система:  

      chmod +x ./a.out


Вот теперь её можно запустить(чтобы это сделать напишите в окне терминала путь к ней): 

      ./a.out


##############################################################################################

Чтобы не терять время, можно все команды соединить в одну строку записав в окне терминала вот так:  

        gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out

##############################################################################################