struct position
{
  int x, y;
};

position getPositionPlayer(char** map); // Возвращает указатель на позицию игрока
position getPositionDoor(char** map); // Возвращает указатель на выход
bool equals(position, position);
