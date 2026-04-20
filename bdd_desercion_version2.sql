CREATE DATABASE  IF NOT EXISTS `ver2_Desercion_Escolar` /*!40100 DEFAULT CHARACTER SET ascii */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `ver2_Desercion_Escolar`;
-- MySQL dump 10.13  Distrib 8.0.36, for Linux (x86_64)
--
-- Host: 127.0.0.1    Database: ver2_Desercion_Escolar
-- ------------------------------------------------------
-- Server version	8.0.41-0ubuntu0.24.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Alumnos`
--

DROP TABLE IF EXISTS `Alumnos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Alumnos` (
  `idAlumno` int NOT NULL AUTO_INCREMENT,
  `nombreAlumno` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_spanish_ci NOT NULL,
  `apellidoAlumno` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_spanish_ci NOT NULL,
  `edadAlumno` int NOT NULL,
  `idCurso` int NOT NULL,
  PRIMARY KEY (`idAlumno`),
  KEY `fk_alumno_curso` (`idCurso`),
  CONSTRAINT `fk_alumno_curso` FOREIGN KEY (`idCurso`) REFERENCES `Cursos` (`idCurso`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=ascii;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Alumnos`
--

LOCK TABLES `Alumnos` WRITE;
/*!40000 ALTER TABLE `Alumnos` DISABLE KEYS */;
INSERT INTO `Alumnos` VALUES (1,'Quimey','Fernandez',11,1),(3,'Felicitas','Martyniuk',17,2),(5,'Jose','Lopez',14,1);
/*!40000 ALTER TABLE `Alumnos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `AsistenciasAlumno`
--

DROP TABLE IF EXISTS `AsistenciasAlumno`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `AsistenciasAlumno` (
  `idAsistencia` int NOT NULL AUTO_INCREMENT,
  `idAlumno` int NOT NULL,
  `fechaAsistencia` date NOT NULL,
  `semana` int NOT NULL,
  PRIMARY KEY (`idAsistencia`),
  UNIQUE KEY `idAlumno` (`idAlumno`,`fechaAsistencia`),
  CONSTRAINT `fk_asistencia` FOREIGN KEY (`idAlumno`) REFERENCES `Alumnos` (`idAlumno`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `AsistenciasAlumno`
--

LOCK TABLES `AsistenciasAlumno` WRITE;
/*!40000 ALTER TABLE `AsistenciasAlumno` DISABLE KEYS */;
/*!40000 ALTER TABLE `AsistenciasAlumno` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Cursos`
--

DROP TABLE IF EXISTS `Cursos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Cursos` (
  `idCurso` int NOT NULL AUTO_INCREMENT,
  `nombreCurso` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL,
  PRIMARY KEY (`idCurso`),
  UNIQUE KEY `nombreCurso` (`nombreCurso`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=ascii;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Cursos`
--

LOCK TABLES `Cursos` WRITE;
/*!40000 ALTER TABLE `Cursos` DISABLE KEYS */;
INSERT INTO `Cursos` VALUES (1,'1°1°'),(2,'2°1°'),(3,'3°1°'),(4,'4°1°'),(5,'5°1°'),(6,'6°1°');
/*!40000 ALTER TABLE `Cursos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `FaltasAlumno`
--

DROP TABLE IF EXISTS `FaltasAlumno`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `FaltasAlumno` (
  `idFalta` int NOT NULL AUTO_INCREMENT,
  `idAlumno` int NOT NULL,
  `fechaFaltaAlu` date NOT NULL,
  `idMotFalta` int NOT NULL,
  `semana` int NOT NULL,
  PRIMARY KEY (`idFalta`),
  UNIQUE KEY `idAlumno` (`idAlumno`,`fechaFaltaAlu`),
  KEY `idMotFalta` (`idMotFalta`),
  CONSTRAINT `FaltasAlumno_ibfk_1` FOREIGN KEY (`idAlumno`) REFERENCES `Alumnos` (`idAlumno`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `FaltasAlumno_ibfk_2` FOREIGN KEY (`idMotFalta`) REFERENCES `motivoFalta` (`idMotFalta`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `FaltasAlumno`
--

LOCK TABLES `FaltasAlumno` WRITE;
/*!40000 ALTER TABLE `FaltasAlumno` DISABLE KEYS */;
/*!40000 ALTER TABLE `FaltasAlumno` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Feriados`
--

DROP TABLE IF EXISTS `Feriados`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Feriados` (
  `id` int NOT NULL AUTO_INCREMENT,
  `fecha` date NOT NULL,
  `nombre` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_spanish_ci NOT NULL,
  `descripcion` text CHARACTER SET utf8mb4 COLLATE utf8mb4_spanish_ci,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=ascii;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Feriados`
--

LOCK TABLES `Feriados` WRITE;
/*!40000 ALTER TABLE `Feriados` DISABLE KEYS */;
INSERT INTO `Feriados` VALUES (1,'2024-01-01','Año Nuevo','Celebración del inicio del año nuevo'),(2,'2024-02-12','Carnaval','Fiesta tradicional de carnaval'),(3,'2024-02-13','Carnaval','Segundo día de carnaval'),(4,'2024-03-24','Día Nacional de la Memoria por la Verdad y la Justicia','Día de conmemoración de las víctimas del terrorismo de Estado'),(5,'2024-03-29','Viernes Santo','Día religioso cristiano'),(6,'2024-04-01','Día del Veterano y de los Caídos en la Guerra de Malvinas','Día de conmemoración a los veteranos y caídos en la guerra de Malvinas'),(7,'2024-05-01','Día del Trabajador','Día internacional de los trabajadores'),(8,'2024-05-25','Día de la Revolución de Mayo','Celebración de la Revolución de Mayo'),(9,'2024-06-17','Paso a la Inmortalidad del General Don Martín Miguel de Güemes','Día de conmemoración del general Güemes'),(10,'2024-06-20','Día de la Bandera','Día de la independencia argentina'),(11,'2024-06-21','Feriado Puente y Turístico','Feriado puente turístico'),(12,'2024-07-09','Día de la Independencia','Día de la independencia argentina'),(13,'2024-08-17','Paso a la Inmortalidad del Gral. José de San Martín','Día de conmemoración del general San Martín'),(14,'2024-10-12','Día del Respeto a la Diversidad Cultural','Día de conmemoración a la diversidad cultural'),(15,'2024-11-18','Día de la Soberanía Nacional','Día de conmemoración de la soberanía nacional'),(16,'2024-12-08','Día de la Virgen','Día religioso cristiano'),(17,'2024-12-25','Navidad','Celebración de la Navidad');
/*!40000 ALTER TABLE `Feriados` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `MiembrosDOE`
--

DROP TABLE IF EXISTS `MiembrosDOE`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `MiembrosDOE` (
  `id_DOE` int NOT NULL AUTO_INCREMENT,
  `nombre_MDOE` varchar(150) NOT NULL,
  `apellido_MDOE` varchar(150) NOT NULL,
  `idCuenta_MDOE` int NOT NULL,
  PRIMARY KEY (`id_DOE`),
  KEY `fk_miembros_doe` (`idCuenta_MDOE`),
  CONSTRAINT `fk_miembros_doe` FOREIGN KEY (`idCuenta_MDOE`) REFERENCES `Usuario` (`idUsuario`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=ascii;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `MiembrosDOE`
--

LOCK TABLES `MiembrosDOE` WRITE;
/*!40000 ALTER TABLE `MiembrosDOE` DISABLE KEYS */;
INSERT INTO `MiembrosDOE` VALUES (1,'Carolina','Ferrero',4),(2,'Sergio','Ioppolo',5),(3,'Julio','Toni',6),(4,'Walter','White',11),(5,'Nahuel','Ledo',12),(6,'Maria','Eugenia',13);
/*!40000 ALTER TABLE `MiembrosDOE` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Preceptores`
--

DROP TABLE IF EXISTS `Preceptores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Preceptores` (
  `idPrece` int NOT NULL AUTO_INCREMENT,
  `nombrePrece` varchar(150) NOT NULL,
  `apellidoPrece` varchar(150) NOT NULL,
  `idCuentaPrece` int NOT NULL,
  `idCurso` int NOT NULL,
  PRIMARY KEY (`idPrece`),
  UNIQUE KEY `idCuentaPrece_UNIQUE` (`idCuentaPrece`),
  CONSTRAINT `fk1_preceptores` FOREIGN KEY (`idCuentaPrece`) REFERENCES `Usuario` (`idUsuario`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=ascii;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Preceptores`
--

LOCK TABLES `Preceptores` WRITE;
/*!40000 ALTER TABLE `Preceptores` DISABLE KEYS */;
INSERT INTO `Preceptores` VALUES (1,'Constanza','Ghergerian',1,1),(2,'Hector','Fernandez',2,2),(3,'Monica','Lopez',3,3),(4,'Norma','Aloma',8,4),(5,'Nestor','Quinones',9,5),(6,'Alejandro','Rodriguez',10,6);
/*!40000 ALTER TABLE `Preceptores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Preguntas_Seguridad`
--

DROP TABLE IF EXISTS `Preguntas_Seguridad`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Preguntas_Seguridad` (
  `idPregunta` int NOT NULL AUTO_INCREMENT,
  `tituloPregunta` varchar(100) NOT NULL,
  PRIMARY KEY (`idPregunta`),
  UNIQUE KEY `descripPregunta_UNIQUE` (`tituloPregunta`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=ascii;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Preguntas_Seguridad`
--

LOCK TABLES `Preguntas_Seguridad` WRITE;
/*!40000 ALTER TABLE `Preguntas_Seguridad` DISABLE KEYS */;
INSERT INTO `Preguntas_Seguridad` VALUES (1,'Color favorito'),(3,'Libro favorito'),(2,'Nombre de tu primer mascota'),(5,'Pais de nacimiento'),(6,'Pelicula favorita'),(4,'Plato de comida preferido');
/*!40000 ALTER TABLE `Preguntas_Seguridad` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Reuniones`
--

DROP TABLE IF EXISTS `Reuniones`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Reuniones` (
  `idReunion` int NOT NULL AUTO_INCREMENT,
  `fechaReunion` date NOT NULL,
  `motivoReunion` varchar(300) NOT NULL,
  `idUsuario` int DEFAULT NULL,
  `idAlumno` int DEFAULT NULL,
  `justificPadre` varchar(300) NOT NULL DEFAULT 'Nada por ahora',
  PRIMARY KEY (`idReunion`),
  KEY `fk_Reuniones_1_idx` (`idAlumno`),
  KEY `fk_Reuniones_2_idx` (`idUsuario`),
  CONSTRAINT `fk_Reuniones_1` FOREIGN KEY (`idAlumno`) REFERENCES `Alumnos` (`idAlumno`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_Reuniones_2` FOREIGN KEY (`idUsuario`) REFERENCES `Usuario` (`idUsuario`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=ascii;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Reuniones`
--

LOCK TABLES `Reuniones` WRITE;
/*!40000 ALTER TABLE `Reuniones` DISABLE KEYS */;
/*!40000 ALTER TABLE `Reuniones` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Usuario`
--

DROP TABLE IF EXISTS `Usuario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Usuario` (
  `idUsuario` int NOT NULL AUTO_INCREMENT,
  `mailUsuario` varchar(150) NOT NULL,
  `contraUsuario` varchar(150) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL,
  PRIMARY KEY (`idUsuario`),
  UNIQUE KEY `mailUsuario` (`mailUsuario`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=ascii;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Usuario`
--

LOCK TABLES `Usuario` WRITE;
/*!40000 ALTER TABLE `Usuario` DISABLE KEYS */;
INSERT INTO `Usuario` VALUES (1,'preceptor1@bue.edu.ar','contrasena123'),(2,'preceptor2@bue.edu.ar','contrasena123'),(3,'preceptor3@bue.edu.ar','contrasena123'),(4,'carolina.ferrero@bue.edu.ar','contrasena456'),(5,'sergio.ioppolo@bue.edu.ar','contrasena456'),(6,'julio.toni@bue.edu.ar','contrasena456'),(8,'preceptor4@bue.edu.ar','contrasena123'),(9,'preceptor5@bue.edu.ar','contrasena123'),(10,'preceptor6@bue.edu.ar','contrasena123'),(11,'walter.white@bue.edu.ar','contrasena456'),(12,'nahuel.ledo@bue.edu.ar','contrasena456'),(13,'maria.eugenia@bue.edu.ar','contrasena456');
/*!40000 ALTER TABLE `Usuario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `motivoFalta`
--

DROP TABLE IF EXISTS `motivoFalta`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `motivoFalta` (
  `idMotFalta` int NOT NULL AUTO_INCREMENT,
  `descripMotFalta` varchar(200) NOT NULL,
  PRIMARY KEY (`idMotFalta`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `motivoFalta`
--

LOCK TABLES `motivoFalta` WRITE;
/*!40000 ALTER TABLE `motivoFalta` DISABLE KEYS */;
INSERT INTO `motivoFalta` VALUES (1,'Enfermedades/Problemas de salud'),(2,'Torneos como representante federado'),(3,'Fallecimiento de un familiar directo'),(4,'Mudanza'),(5,'Festividades religiosas'),(6,'Viajes particulares'),(7,'Motivos particulares');
/*!40000 ALTER TABLE `motivoFalta` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `respuestas_seguridad`
--

DROP TABLE IF EXISTS `respuestas_seguridad`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `respuestas_seguridad` (
  `idRespuesta` int NOT NULL AUTO_INCREMENT,
  `idUsuario` int NOT NULL,
  `idPregunta` int NOT NULL,
  `respuesta` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL,
  PRIMARY KEY (`idRespuesta`),
  KEY `idUsuario` (`idUsuario`),
  KEY `idPregunta` (`idPregunta`),
  CONSTRAINT `respuestas_seguridad_ibfk_1` FOREIGN KEY (`idUsuario`) REFERENCES `Usuario` (`idUsuario`) ON DELETE CASCADE,
  CONSTRAINT `respuestas_seguridad_ibfk_2` FOREIGN KEY (`idPregunta`) REFERENCES `Preguntas_Seguridad` (`idPregunta`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=ascii;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `respuestas_seguridad`
--

LOCK TABLES `respuestas_seguridad` WRITE;
/*!40000 ALTER TABLE `respuestas_seguridad` DISABLE KEYS */;
INSERT INTO `respuestas_seguridad` VALUES (1,1,1,'Azul'),(2,3,1,'Rosa'),(3,8,1,'Amarillo'),(4,9,1,'Naranja');
/*!40000 ALTER TABLE `respuestas_seguridad` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-02-17 22:57:17
