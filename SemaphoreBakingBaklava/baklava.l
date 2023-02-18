.TH 171419006_baklava.c 1
.SH NAME
171419006_baklava.c - Bir baklava üretimi ve malzeme dağıtımını Threadler ile simüle eder.
.SH SYNOPSIS
[dukkani_ac]
[sevkiyata_basla]
[malzeme_belirle]
[malzeme_dagit]
[baklava_yap]
.SH DESCRIPTION
Bu program 6 adet dükkanın(thread), bir dağıtıcının(thread) getirdiği malzemelerden, kendisinde bulunmayanları alarak baklava üretmesini ve dağıtıcıya bunu verip satmasını simüle eder. Program sonsuza kadar dönen bir satış zinciri oluşturur
.SH FUNCTIONS
.TP
.BR dukkani_ac
Dükkanlara ait threadleri başlatır. 
.TP
.BR sevkiyata_basla
Dağıtıcıya ait threadi başlatır.
.TP
.BR malzeme_belirle
malzeme.txt'den bir malzeme ikilisi okur.
.TP
.BR malzeme_dagit
Txt dosyasından okunan malzemeleri dükkanları dolaşarak dağıtır.
.TP
.BR baklava_yap
Dükkanlar 4 malzemeye sahip olduğunda, o dükkanın ustası(thread)'i çağrılır ve baklava yaptırılır.
