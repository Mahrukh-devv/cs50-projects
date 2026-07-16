SELECT name FROM songs WHERE energy > (SELECT AVG(energy) FROM songs);
