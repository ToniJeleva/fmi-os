# Операционни системи
по мотиви от записките на Йордан Бабуков

##Документация
###Manual sections (`man man`)

* `1   Executable programs or shell commands`
* `2   System calls (functions provided by the kernel)`
* `3   Library calls (functions within program libraries)`
* `4   Special files (usually found in /dev)`
* `5   File formats and conventions eg /etc/passwd`
* `6   Games`
* `7   Miscellaneous  (including  macro  packages  and  conventions), e.g. man(7), groff(7)`
* `8   System administration commands (usually only for root)`
* `9   Kernel routines [Non standard]`

###Пакети

* Debian `apt-get install manpages-dev manpages-dev`

##Cистемни примитиви на C за работа с файлове

* open(2) `int open(const char *pathname, int flags);`
* close(2) `int close(int fd);`
* read(2) `ssize_t read(int fd, void *buf, size_t count);`
* write(2) `ssize_t write(int fd, const void *buf, size_t count);`