USE [master]
GO
/****** Object:  Database [Test]    Script Date: 8/20/2018 11:15:30 AM ******/
CREATE DATABASE [Test]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'Test', FILENAME = N'C:\Program Files (x86)\Microsoft SQL Server\MSSQL11.SQLEXPRESS\MSSQL\DATA\Test.mdf' , SIZE = 3072KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'Test_log', FILENAME = N'C:\Program Files (x86)\Microsoft SQL Server\MSSQL11.SQLEXPRESS\MSSQL\DATA\Test_log.ldf' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [Test] SET COMPATIBILITY_LEVEL = 110
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [Test].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [Test] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [Test] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [Test] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [Test] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [Test] SET ARITHABORT OFF 
GO
ALTER DATABASE [Test] SET AUTO_CLOSE ON 
GO
ALTER DATABASE [Test] SET AUTO_CREATE_STATISTICS ON 
GO
ALTER DATABASE [Test] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [Test] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [Test] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [Test] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [Test] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [Test] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [Test] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [Test] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [Test] SET  DISABLE_BROKER 
GO
ALTER DATABASE [Test] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [Test] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [Test] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [Test] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [Test] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [Test] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [Test] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [Test] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [Test] SET  MULTI_USER 
GO
ALTER DATABASE [Test] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [Test] SET DB_CHAINING OFF 
GO
ALTER DATABASE [Test] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [Test] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
USE [Test]
GO
/****** Object:  Table [dbo].[HARGA]    Script Date: 8/20/2018 11:15:30 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[HARGA](
	[id_jenis] [int] NOT NULL,
	[nama_toko] [varchar](50) NULL,
	[harga] [int] NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[test_ixobox]    Script Date: 8/20/2018 11:15:30 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[test_ixobox](
	[no] [int] IDENTITY(1,1) NOT NULL,
	[id_scan] [varchar](50) NULL,
	[flag] [int] NULL,
	[status] [varchar](50) NULL,
	[id_stylist] [int] NULL,
	[kursi] [int] NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[User]    Script Date: 8/20/2018 11:15:30 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[User](
	[User_id] [int] NOT NULL,
	[Nama_user] [varchar](50) NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[HARGA] ([id_jenis], [nama_toko], [harga]) VALUES (1, N'Mall Sunter', 50000)
SET IDENTITY_INSERT [dbo].[test_ixobox] ON 

INSERT [dbo].[test_ixobox] ([no], [id_scan], [flag], [status], [id_stylist], [kursi]) VALUES (1, N'0001', 0, N'Available', 0, 0)
INSERT [dbo].[test_ixobox] ([no], [id_scan], [flag], [status], [id_stylist], [kursi]) VALUES (2, N'0012', 0, N'Available', 0, 0)
INSERT [dbo].[test_ixobox] ([no], [id_scan], [flag], [status], [id_stylist], [kursi]) VALUES (3, N'0013', 0, N'Available', 0, 0)
INSERT [dbo].[test_ixobox] ([no], [id_scan], [flag], [status], [id_stylist], [kursi]) VALUES (4, N'0014', 0, N'Available', 0, 0)
INSERT [dbo].[test_ixobox] ([no], [id_scan], [flag], [status], [id_stylist], [kursi]) VALUES (5, N'0015', 0, N'Available', 0, 0)
INSERT [dbo].[test_ixobox] ([no], [id_scan], [flag], [status], [id_stylist], [kursi]) VALUES (6, N'0017', 1, N'Expired', 89, 2)
INSERT [dbo].[test_ixobox] ([no], [id_scan], [flag], [status], [id_stylist], [kursi]) VALUES (7, N'0016', 0, N'Expired', 14, 1)
SET IDENTITY_INSERT [dbo].[test_ixobox] OFF
INSERT [dbo].[User] ([User_id], [Nama_user]) VALUES (123, N'Admin')
INSERT [dbo].[User] ([User_id], [Nama_user]) VALUES (456, N'sasa')
INSERT [dbo].[User] ([User_id], [Nama_user]) VALUES (14, N'Anton')
USE [master]
GO
ALTER DATABASE [Test] SET  READ_WRITE 
GO
