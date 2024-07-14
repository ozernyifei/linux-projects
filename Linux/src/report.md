## Part 1. Установка ОС

Сообщение с установленной версией Linux: 

![alt text](part1.png)

## Part 2. Создание пользователя

![alt text](part2_create_user.png)

![alt text](part2_user_group_info.png)


## Part 3. Настройка сети ОС

![alt text](part3_rename_pc.png)

![alt text](part3_change_timezone.png)

![alt text](part3_ext_int_ip.png)

![alt text](part3_dhcp_ip.png)

![alt text](part3_local_ip.png)

lo или local loopback (локальная петля). Служит для подключения по сети к этому же компьютеру и не требует дополнительной настройки;

![alt text](part3_dhcp_on.png)

Dynamic Host Configuration Protocol (DHCP) — автоматический предоставляет IP адреса и прочие настройки сети (маску сети, шлюз и т.п) компьютерам и различным устройствам в сети.

![alt text](part3_dhcp_off_ip_static.png)

![alt text](part3_ping_1_ya.png)

## Part 4. Обновление ОС

Обновить системные пакеты до последней на момент выполнения задания версии

![alt text](part4_update_apt.png)

## Part 5. Использование команды **sudo**

Sudo — это утилита, предоставляющая привилегии root для выполнения административных операций в соответствии со своими настройками. Она позволяет легко контролировать доступ к важным приложениям в системе. По умолчанию, при установке Ubuntu первому пользователю (тому, который создаётся во время установки) предоставляются полные права на использование sudo. Т.е. фактически первый пользователь обладает той же свободой действий, что и root. 

![alt text](part5_add_sudo_change_pc_name.png)

## Part 6. Установка и настройка службы времени

Настроить службу автоматической синхронизации времени.
Вывод следующей команды должен содержать NTPSynchronized=yes: timedatectl show 

![alt text](part6_already_done_by_system.png)

## Part 7. Установка и использование текстовых редакторов 

Установить текстовые редакторы VIM (+ любые два по желанию NANO, MCEDIT, JOE и т.д.)
sudo apt install vim
sudo apt install nano
sudo apt install mcedit
Используя каждый из трех выбранных редакторов, создайте файл test_X.txt, где X -- название редактора, в котором создан файл. Напишите в нём свой никнейм, закройте файл с сохранением изменений.
Используя каждый из трех выбранных редакторов, откройте файл на редактирование, отредактируйте файл, заменив никнейм на строку "21 School 21", закройте файл без сохранения изменений.
Используя каждый из трех выбранных редакторов, отредактируйте файл ещё раз (по аналогии с предыдущим пунктом), а затем освойте функции поиска по содержимому файла (слово) и замены слова на любое другое

![alt text](part7_vim_install.png)

![alt text](part7_nano_install.png)

![alt text](part7_mcedit_install.png)

![alt text](part7_vim_new_text.png)

![alt text](part7_vim_edit_no_save.png)

![alt text](part7_vim_edit_via_tools.png)


    vim test_VIM.txt
    Режим редактирования: I
    Выйти из режима редактирования: esc
    Выход с охранением: :wq
    Выход без сохранения: :q
    Поиск: /<текст, который хотим найти>
    Замена: :s/<что хотим изменить>/<на что хотим заменить>


![alt text](part7_mcedit_new_text.png)

![alt text](part7_mcedit_edit_no_save.png)

![alt text](part7_mcedit_search.png)

![alt text](part7_mcedit_edit_via_tools.png)


    mcedit test_mcedit.txt
    Выход с охранением: F2 (yes) + F10
    Выход без сохранения: F10(no)
    Поиск: F7 + <текст который ищем> + <ок>
    Замена: F4 + <что хотим изменить> + <на что хотим заменить> + replace


![alt text](part7_nano_new_text.png)

![alt text](part7_nano_edit_no_save.png)

![alt text](part7_nano_search.png)

![alt text](part7_nano_edit_tools.png)


    nano test_NANO.txt
    Выход с охранением: CTRL + x, затем y b enter
    Выход без сохранения: CTRL + x, затем n
    Поиск: CTRL + W, затем enter (alt + w для перехода к след. вхождению, ctrl + c для преращения поиска)
    Замена: CTRL + + <что хотим изменить + enter> + <на что хотим заменить + enter> + A(для замены все вхождения) или y и n по отдельности


## Part 8. Установка и базовая настройка сервиса **SSHD**

sudo apt-get install ssh
sudo apt install openssh-server 

![alt text](part8_install_ssh.png)

sudo systemctl enable ssh
systemctl status ssh 

![alt text](part8_add_ssh_to_autostart_and_status.png)

sudo vim /etc/ssh/sshd_config 

![alt text](part8_change_port_to_2022.png)

systemctl restart sshd

ps (показывает запущенные процессы, выполняемые пользователем в окне терминала);
ps -e или ps -A (Чтобы просмотреть все запущенные процессы);
ps -d (Чтобы показать все процессы, кроме лидеров сессии);
ps -d -N (можно инвертировать вывод с помощью переключателя -N. Например, если хочу вывести только лидеров сеансов)
ps T (увидеть только процессы, связанные с этим терминалом);
ps r (просмотреть все работающие (running) процессы);
ps -p 'pid' (если вы знаете идентификатор процесса PID, вы можете просто использовать следующую команду, для вывода процесса с этим 'pid');
ps -p 'pid1' 'pid2'
ps U 'userlist' (найти все процессы, выполняемые конкретным пользователем);
ps -ef (получить полный список); 

![alt text](part8_used_commands.png)

![alt text](part8_find_sshd.png)


    -t (--tcp) отображает соедниеня только по tcp
    -a (--all) вывод всех активных подключений TCP
    -n (--numeric) вывод активных подключений TCP с отображением адресов и номеров портов в числовом формате
    Proto: Название протокола (протокол TCP или протокол UDP);
    recv-Q: очередь получения сети
    send-Q: Сетевая очередь отправки
    Local Address адрес локального компьтера и используемы номер порта
    Foreign Address адрес и номер удаленного компьтера к которомц подключен сокет
    State состояние сокетв
    0.0.0.0 означает IP-адрес на локальной машине


![alt text](part8_netstat.png)

## Part 9. Установка и использование утилит **top**, **htop**

![alt text](part9_top.png)

![alt text](part9_htop_pid.png)

![alt text](part9_htop_p_cpu.png)

![alt text](part9_htop_p_mem.png)

![alt text](part9_htop_time.png)

![alt text](part9_htop_sshd_filter.png)

![alt text](part9_htop_syslog_search.png)

![alt text](part9_htop_uptime_clock_hostname.png)

## Part 10. Использование утилиты **fdisk**

![alt text](part10_fdisk_result.png)

![alt text](part10_swap_size.png)

## Part 11. Использование утилиты **df** 

![alt text](part11_simple_df.png)

![alt text](part11_df_th.png)

## Part 12. Использование утилиты **du**

![alt text](part12_du_simple.png)

![alt text](part12_du_homevarlog_humanr.png)

![alt text](part12_du_star_var_log.png)

## Part 13. Установка и использование утилиты **ncdu**

![alt text](part13_ncdu_home.png)

![alt text](part13_ncdu_var.png)

![alt text](part13_ncdu_var_log.png)

## Part 14. Работа с системными журналами

![alt text](part14_bullshit_1_dmesg.png)

![alt text](part14_bullshit_2_syslog.png)

![alt text](part14_bullshit_3_auth.png)

![alt text](part14_auth_result.png)

![alt text](part14_grepped_sshd_restart.png)

## Part 15. Использование планировщика заданий **CRON**

![alt text](part15_cron_delete.png)