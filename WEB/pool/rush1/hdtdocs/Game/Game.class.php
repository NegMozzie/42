<?php
require_once 'player/Player.class.php';
require_once 'doc/Doc.class.php';

class Game
{
	private $_gid = 1;
	private $_pid = 1;
	private $_players = array();
	private bool $_end = FALSE;
	public static $verbose = FALSE;
	
	use Doc;
	
	public function __construct($id)
	{
		$this->_gid = $id;
		$db = new Database();
		$this->players = $db->getPlayers($id);
	}

	public function getPlayers() {return $this->_players; }
	public function getEndgame() { return $this->_endGame;}
	public function setEnd($_endGame){ $this->_endGame = $_endGame;}
	public function getId() { return $this->_id_game; }
	public function setId($id_game) { $this->_id_game = $id_game;}
}
?>