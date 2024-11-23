-- MySQL dump 10.13  Distrib 8.0.35, for Linux (x86_64)
--
-- Host: localhost    Database: Shop
-- ------------------------------------------------------
-- Server version	8.0.35-0ubuntu0.23.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Additation`
--

DROP TABLE IF EXISTS `Additation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Additation` (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` date NOT NULL,
  `reason` text,
  `expense` int NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Additation`
--

LOCK TABLES `Additation` WRITE;
/*!40000 ALTER TABLE `Additation` DISABLE KEYS */;
INSERT INTO `Additation` VALUES (2,'2024-11-20','vvvv',40),(3,'2024-11-16','bbb',20),(4,'2024-10-17','adada',450),(5,'2024-11-14','axper',6),(6,'2024-11-14','axper',12543),(7,'2024-11-14','axper',12543);
/*!40000 ALTER TABLE `Additation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Bank`
--

DROP TABLE IF EXISTS `Bank`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Bank` (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` date NOT NULL,
  `reason` text,
  `expense` int NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Bank`
--

LOCK TABLES `Bank` WRITE;
/*!40000 ALTER TABLE `Bank` DISABLE KEYS */;
INSERT INTO `Bank` VALUES (2,'2024-11-21','',1),(3,'2024-11-21','',1),(4,'2024-11-21','',1),(5,'2024-11-21','',1),(6,'2024-11-21','',200),(7,'2024-11-21','',200),(8,'2024-11-21','',450),(9,'2024-11-21','',450),(10,'2024-11-21','Hello',240),(11,'2024-11-21','Hello',240),(12,'2024-11-21','',200);
/*!40000 ALTER TABLE `Bank` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Cash`
--

DROP TABLE IF EXISTS `Cash`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Cash` (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` date NOT NULL,
  `reason` text,
  `expense` int NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Cash`
--

LOCK TABLES `Cash` WRITE;
/*!40000 ALTER TABLE `Cash` DISABLE KEYS */;
INSERT INTO `Cash` VALUES (2,'2024-11-20','world',44),(3,'2024-11-19','Ha',350),(4,'2024-11-29','sasasa',465),(5,'2024-11-13','hashhhh',700);
/*!40000 ALTER TABLE `Cash` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Transfer`
--

DROP TABLE IF EXISTS `Transfer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Transfer` (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` date NOT NULL,
  `reason` text,
  `expense` int NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Transfer`
--

LOCK TABLES `Transfer` WRITE;
/*!40000 ALTER TABLE `Transfer` DISABLE KEYS */;
INSERT INTO `Transfer` VALUES (2,'2024-11-20','world',456),(3,'2024-11-23','trans',321),(4,'2024-11-05','HELLO AAAAA',333);
/*!40000 ALTER TABLE `Transfer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Users`
--

DROP TABLE IF EXISTS `Users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Users` (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `surname` varchar(50) DEFAULT NULL,
  `password` varchar(255) NOT NULL,
  `login` varchar(50) NOT NULL,
  `role` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `login` (`login`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Users`
--

LOCK TABLES `Users` WRITE;
/*!40000 ALTER TABLE `Users` DISABLE KEYS */;
INSERT INTO `Users` VALUES (1,NULL,NULL,'admin','admin','admin');
/*!40000 ALTER TABLE `Users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-11-23 17:58:28
