<?php
/* Tener una lista de ciudades con un 
clima y una ubicación específica */

# Función
function recomendacion(){
    // Se crean los diferentes arrays.
    $clima = array("Bogota" => "Frio", "Monteria" => "Calido", "Medellin" => "Templado");
    
    $ubicacion = array("Guajira" => "Norte", "Leticia" => "Sur", "Santander" => "Este", "Antioquia" => "Oeste");
     
    $turismo = array("Santa Marta" => "Mar", "Villavicencio" => "Llanos", "Riohacha" => "Desierto", "Quindio" => "Valle");
    
    /* A través de la función readline se escriben en consola las opciones de interés correspondientes a los 3 arrays construidos con anterioridad, el valor ingresado por el usuario en consola se guarda en la variable $search.*/
    do {
        $search = intval(readline("Seleccione la opción de su interés: \n1.Clima 2.Ubicación 3.Turismo 4. Salir \nOpción: "));
    
        /* Se genera la estructura switch evaluando la variable $search y dependiendo de la opción elegida se generan otras estructuras switch anidadas y se remiten a los valores "llave o clave" dentro del array correspondiente y de acuerdo al "valor" como parámetro de búsqueda. */
        switch($search){
            case 1:
                $clima_opcion = readline("Seleccione el clima favorito: \n1.Frío 2.Cálido 3.Templado \nOpción: ");
                switch($clima_opcion){
                    case 1:
                        $clave = array_search('Frio', $clima); 
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break;
                    case 2:
                        $clave = array_search('Calido', $clima);
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break;
                    case 3:
                        $clave = array_search('Templado', $clima);
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break; 
                }
                break;
    
            case 2:
                $ubicacion_opcion = readline("Seleccione la ubicación favorita: \n1.Norte 2.Sur 3.Este 4.Oeste \nOpción: ");
                switch($ubicacion_opcion){
                    case 1:
                        $clave = array_search('Norte', $ubicacion); 
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break;
                    case 2:
                        $clave = array_search('Sur', $ubicacion);
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break;
                    case 3:
                        $clave = array_search('Este', $ubicacion);
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break; 
                    case 4:
                        $clave = array_search('Oeste', $ubicacion);
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break; 
                }
                break;
      
            case 3:
                $turismo_opcion = readline("Seleccione el turismo favorito: \n1.Mar 2.Llanos 3.Desierto 4.Valle \nOpción: ");
                switch($turismo_opcion){
                    case 1:
                        $clave = array_search('Mar', $turismo); 
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break;
                    case 2:
                        $clave = array_search('Llanos', $turismo);
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break;
                    case 3:
                        $clave = array_search('Desierto', $turismo);
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break; 
                    case 4:
                        $clave = array_search('Valle', $turismo);
                        echo "La ciudad recomendada es " . $clave . "\n";
                        break; 
                }
                break;
            
            case 4:
                echo "\n Saliendo del programa...\n";
                break;
                
            default:
                echo "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while ($search != 4); // Repetir hasta que el usuario seleccione la opción 4 (Salir).
}

recomendacion();
?>
