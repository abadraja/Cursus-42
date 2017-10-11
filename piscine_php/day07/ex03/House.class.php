<?php
abstract class House
{

	public function introduce()
	{
		print("House " . $this->getHouseName() . " of " . $this->getHouseSeat() . " : \"" . $this->getHouseMotto() . "\"" . PHP_EOL);
	}

	abstract public function getHouseName();

	abstract public function getHouseMotto();

	abstract public function getHouseSeat();

}
?>