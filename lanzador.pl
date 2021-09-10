#!/usr/bin/perl

#Fichero para automatización de ejecución por lotes de un ejecutable
#dado parametros de entrada

$repeticiones = 30;
@ejecutables = ("matricesApp");
@matrizSize = ("400 6","600 6","800 6","1000 6","2000 6","4000 6","6000 6");
$path = "/home/maria/matrices_05_hilos/";

foreach $exe (@ejecutables) {
	foreach $size (@matrizSize) {
		$fichero = "$path"."Soluciones6/"."$exe"."-size"."$size";
		#print("$fichero \n");
		for($i =0; $i<$repeticiones; $i++) {
			#print("$path$exe $size \n");
			system("$path$exe $size >> $fichero");
		}
	}
}

exit(1);
