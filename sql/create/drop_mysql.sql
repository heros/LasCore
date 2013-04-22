REVOKE ALL PRIVILEGES ON * . * FROM 'infinity'@'localhost';

REVOKE ALL PRIVILEGES ON `world` . * FROM 'infinity'@'localhost';

REVOKE GRANT OPTION ON `world` . * FROM 'infinity'@'localhost';

REVOKE ALL PRIVILEGES ON `characters` . * FROM 'infinity'@'localhost';

REVOKE GRANT OPTION ON `characters` . * FROM 'infinity'@'localhost';

REVOKE ALL PRIVILEGES ON `auth` . * FROM 'infinity'@'localhost';

REVOKE GRANT OPTION ON `auth` . * FROM 'infinity'@'localhost';

DROP USER 'infinity'@'localhost';

DROP DATABASE IF EXISTS `world`;

DROP DATABASE IF EXISTS `characters`;

DROP DATABASE IF EXISTS `auth`;
