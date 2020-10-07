<?php 
	class Jeu{
		public $resultat;

		public function getRes(){
			for ($i=0; $i < 4; $i++) { 
				$this->$resultat[] = rand(0, 9);
			}
			return $this->$resultat;
		}
	}
 ?>