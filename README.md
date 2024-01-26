# Karadeniz Teknik Üniversitesi Nesne Yönelimli Programlama dersi


## Birinci Ödev:

Bu ödev, C++ programlama dili kullanarak temel dizi işlemleri ve dosya giriş/çıkış işlemleri
hakkında pratiğe dayalı bir deneyim sunmayı amaçlamaktadır. Ödevle ilgili önemli bilgiler
aşağıda yer almaktadır.
- Ödev Kapsamı: Dizi işlemleri ve dosya i/o

  
Ödev Açıklaması:
- Kullanıcıdan bir dizi (dizinin ismi dizi1 olarak adlandırılmalıdır) girişi istenmelidir. dizi1'in
boyutu ve elemanları kullanıcıdan alınmalıdır.
- Bir dosyadan (örneğin "input.txt") başka bir dizi (dizinin ismi dizi2 olarak
adlandırılmalıdır) okunmalıdır. Dosyanın yapısı şu şekildedir: İlk satır dizi2'nin boyutunu
içerir, ardından dizi2'nin elemanları sırayla bulunur. (Örnek gösterim: ElemanSayısı
Elemanlar şeklindedir. 3 2 4 6 gibi)
- dizi1 ve dizi2'nin toplamı ve çarpımı hesaplanmalıdır. Bu toplam ve çarpım işlemleri için
ayrıca fonksiyonlar yazılmadır. (Fonksiyon çağrımlarında kullanılacak parametreler )
- dizi1’deki tek ve çift sayılar bulunmalıdır. Tek sayılar tek olarak adlandırılacak bir diziye
ve çift sayılar ise cift olarak adlandırılacak başka bir diziye yazdırılmalıdır.
Tüm bu işlemler sonucunda elde edilen diziler ve sonuçlar, bir dosyaya (örneğin "output.txt")
yazdırılmalıdır. Dosya yapısı ilk satır dizilerin toplamını, ikinci satır dizilerin çarpımını, üçüncü
satır tek sayıları tutan diziyi, dördüncü satır çift sayıları tutan diziyi gösterecek şekilde olmalıdır.

Örnek Giriş ve Çıkış Değerleri:
Kullanıcıdan alınan ve dosyadan okunan dizi elemanları aşağıdaki gibiyse;
dizi1=[2 5 3 7 8]
dizi2=[9 1 4 2 0]

Sonuç dosyasındaki çıktı şu şekilde olmalıdır:
Toplama işleminin sonucu: 11 6 7 9 8
Çarpma işleminin sonucu: 5 12 14 0
Tek sayıları tutan dizi: 5 3 7
Çift sayıları tutan dizi: 2 8
#### Önemli Notlar:
- Dizi boyutlarının ve elemanlarının doğru bir şekilde alındığından emin olun.
- Tek ve çift sayıları ayırmak için diziler kullanılmalıdır.
- Dizilerin toplamını ve çarpımını hesaplarken, dikkatli bir şekilde dizi elemanlarını işleyin.

## İkinci Ödev:

ÖDEV KONUSU: SEÇİM SONUÇLARI



Yerel bir üniversitenin öğrenci konseyi için başkanlık seçimi yapılacaktır. Gizlilikle ilgili 
nedenlerden dolayı, oylama bilgisayar ortamında yapılacaktır. Verilerin analiz edileceği ve 
kazananın bildirileceği bir program yazılması beklenmektedir. Program ile ilgili detaylar şu 
şekildedir:

Üniversitenin dört ana bölümü vardır ve her bölümün birkaç departmanı vardır. Seçimin amacı 
doğrultusunda, dört bölüm, Bölge 1, Bölge 2, Bölge 3 ve Bölge 4 olarak etiketlenmiştir. Her 
bölümdeki her departman kendi oylama sürecini yönetir ve her adayın aldığı oyları doğrudan 
seçim komitesine bildirir. 

Veriler iki dosya halinde sunulmaktadır. Bir dosya, örneğin candDat.txt, başkanlık makamına 
aday olan isimlerinden oluşmaktadır. Dosyadaki adayların isimleri belirli bir sırada değildir. 


İkinci dosyada, örneğin voteData.txt, her satır aşağıdaki biçimde oylama sonuçlarından 
oluşmaktadır:

adayAdı    bölgeNumarası     BuAdayİçinOySayısı


Örneğin, girdi dosyası şöyle görünür:
Donald 1 23
Pluto 2 56
Doc 1 25
Pluto 4 23
.
.
.
İlk satır Donald'ın 1. bölgeden 23 oy aldığını göstermektedir. NOT: Tüm adayların ayrı 
bölgelerden aldığı oylar Pluto örneğinde olduğu gibi farklı satırlarda yer almalıdır. 


Programa ait Girdi Verileri: Biri aday isimlerini, diğeri yukarıda açıklandığı gibi oy verilerini 
içeren iki dosya.


Çıktı: Seçim sonuçlarının ve kazananın konsol ekranında açıklandığı bir tablo.


ÖDEV AÇIKLAMASI
- Program oylama verilerini bölgelere göre düzenlemelidir. 
- Program ayrıca her adayın aldığı toplam oy sayısını ve seçimde kullanılan toplam oyu 
hesaplamalıdır.
- Adayların isimleri alfabetik sırada görünmelidir. 
- Bir adayın adının veri türü (bir string) ile oy sayısının veri türü (bir integer) farklı 
olduğundan, biri adayların adlarını diğeri de oylama verilerini tutmak için iki ayrı diziye 
ihtiyacımız vardır. 
- Adayların adlarını tutan dizi tek boyutlu bir dizidir ve bu dizinin her bir bileşeni bir 
string’tir. 
- Oylama verilerini tutmak için tek bir iki boyutlu dizi kullanmak yerine, çıktının sonraki 
dört sütununu tutmak için iki boyutlu bir dizi ve her adayın aldığı toplam oyu tutmak 
için tek boyutlu bir dizi kullanılması gerekmektedir. 
NOT: Yapılacak tüm alt işlemler fonksiyonlarla gerçeklenmelidir.


