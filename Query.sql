USE meta2;

DESCRIBE players;
DESCRIBE teams;

SELECT * FROM players;
SELECT * FROM teams;

SELECT players.nickname AS 'Player', teams.name AS 'Team'
FROM players
INNER JOIN Teams
ON players.team_id = teams.id
WHERE players.is_coach = FALSE
ORDER BY Team;

SELECT players.nickname AS 'Player'
FROM players
INNER JOIN Teams
ON players.team_id = teams.id
WHERE teams.name = 'Vikings';

SELECT * FROM players WHERE nickname = 'D1ZZY';

SELECT players.birth, players.country, players.nickname, players.power, teams.name AS 'team'
FROM players
INNER JOIN teams
ON players.team_id = teams.id
WHERE (players.birth > '2000-01-01') 
AND (players.country = 'Canada' OR players.country = 'United States') 
AND (players.power >= 50)
ORDER BY players.power DESC;

ALTER TABLE players
ADD COLUMN is_captain BOOL DEFAULT FALSE,
ADD COLUMN is_coach BOOL DEFAULT FALSE;

ALTER TABLE players
ADD COLUMN is_active BOOL DEFAULT FALSE AFTER power;

ALTER TABLE players
MODIFY COLUMN is_active BOOL NOT NULL DEFAULT FALSE,
MODIFY COLUMN is_coach BOOL NOT NULL DEFAULT FALSE,
MODIFY COLUMN is_captain BOOL NOT NULL DEFAULT FALSE;

UPDATE players SET is_active = TRUE WHERE team_id != 0;

CREATE DATABASE metadb;
RENAME TABLE meta2.players TO metadb.players;
RENAME TABLE meta2.teams TO metadb.teams;

DESCRIBE world.country;
SELECT * FROM world.countrylanguage WHERE Language = 'English' AND IsOfficial = 'T';
SELECT * FROM world.country ORDER BY Population DESC;
