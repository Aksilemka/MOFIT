# MOFIT 

No spoko, da się edytować w internecie ;)

Moja interpretacja programu (tutaj, aby nie brudzić pliku z kodem)

program ma policzyć wartości własne jak damy mu d i l

	d (stała ekranowania) zmienia się o 0<d<inf i jest to stała ekranowania, po prostu będziemy ją sobie podawać i tu nie ma problemu, 
	od niej zależy jak zmieniamy dro0 (jest to opisane w programie), narazie nie wiem po co, ach dro0 jest po prostu parametrem w równaniu, zaraz zobaczymy co dalej
	wiemy jak zmieniać 0<d<inf i kiedy (byle kiedy, na początku programu)
	wiemy jak zmieniać dro0, ale nie wiemy kiedy, bo Bednarek pisze o jakimś pierwszym i drugim kroku, potem pisze, że liczba kroków (iteracji) powinna być 5000, do 20000, a pytanie zadaje: jak długo liczyć z pierwszym krokiem? Wydaje mi się, że zmieszał słowo krok i iteracja, dlatego 5000 to liczba iteracji, a krok odnosi się do dro0, po co zmieniać dro0? po to aby mając już działający program zastosować się do wskazówki i mając już wszystko działające szukać takiego dro0, które da niezmienne wyniki przy nie wielkich modyfikacjach dro0. Podsumowując nie wiem co zrobić z dro0 i nie zmieniałbym go do samego końca, aż wszystko będzie jasne i działające
	
	l (liczba orbitalna) zależy od obranego n, przy czym n=1,2,3..., a l=0,...,n-1, wybieramy je na początku i koniec
	wiemy jak zmieniać n=1,2,3...,
	wiemy jak zmieniać l=0,...,n-1, gdy mamy dane n
	nie wiem, nie rozumiem co ze stanami s, bo opis który daje jest dla mnie nie jasny. Aczkolwiek, być może, gdy się wszystko podstawi w programie, to okaże się, że wystarczyło podstawić i jest wynik od razu.
	
	ro to nasz promień, a jak wiemy funkcje radialne oplatają os r przecinając ją kilka razy w zależności od l (fizyka), wydaje mi się, że dro0 służy do szukania ro0 (przechodzenia wzdłóż osi ro0), dlatego, że aby je znaleźć, to musimy iść wzdłóż osi ro, aż trafimy na takie ro0 (które podajemy w pakiecie z ustalonym d i l na początku działania programu, lub mamy tak rozbudowany program, że on przechodzi sam po wszystkich ro0 zmieniając o dro0 dla ustalonego d i l. UUU, coraz jaśniej widzę ten program.), że nasza funkcja przechodzi przez ten punkt 0 (zmienia znak) i do tego nie zmianiają się wiele wartości własne gdy nieco zmieniamy to ro0. Możemy porozmawiać na skype, fta, jeżeli moje opisy są zbyt pogmatwane. 
	
	gdy wybierzemy wszystkie parametry l, d, ro0, to mamy znaleźć (wartości własne) lambda, te są określone przez miejsce, w którym 
	zmieni znak funkcja R(ro0), czyli mamy wszystko ustalone poza lambda, bierzemy lambda 1 i przepuszczamy R(ro0) przez 5000
	tys iteracji aby je znaleźć (i chyba w każdej kolejnej iteracji musimy zwiększać dro0 i to o tu tu chodziło z tym całym syfem - komentarz NIE PRAWDA, nie tutaj, teraz wydaje mi się, że dro0 zmieniamy ponad tą częścią programu, czyli tak jakby zewnętrzna pętla która dla l i d przechodzi przez różne ro0 zmienijąc o dro0 i wtedy dla każdego przypadku ro0, rozważa różne lambda (co jest kolejnym zagnieżdzeniem) i jeszcze głębiej liczy te 5000 razy Ri aby sprawdzić czy to lambda, dla tego ro0  spełnia zadanie) 
	zapisujemy wartość własną, zwiększamy lammbda i przepuszamy znowu, tak obserwujemy aż nasz wynik zmieni
	znak, teraz trzeba jakość wznaczyć lambda dla którego funkcja jest równa 0, pomiędzy tymi dwoma co się zmienił znak,
	on mówi o jakichś specjlanych metodach, ale nie wiem czy podźwigniemy to inaczej niż np. średnia
	
	wiemy jak zmieniać lambda, zwiększamy o dl=1, chociaż można by zwiększać o coś dużego znaleźć miejsce zmiany, potem wokół
	niego dopiero zmieniać lambda o małe wartości, coś w stylu przetwornika ac
	wiemy jaką wartość początkową nadać lambda0=l+1
	
Inne komentarze:
	jest przypadek z energią zbliżającą się do 0, a wtedy trzeba zwiększyć liczbę iteracji. wydaje mi się, że energia zbliża
	się do zera dla dużych ro0, czyli rozwiązanie funkcji radialnej jest bliskie 0
	
	gdy program działa, to dopiero zaczynamy sotoswać wskazówkę i sprawdzać, które ro0 i dro0 działa
