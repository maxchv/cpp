﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool
//     Changes to this file will be lost if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/// <remarks>Квартира</remarks>
public class Apartment
{
	/// <summary>
	/// Количество комнат в квартире
	/// </summary>
	private int n_chamber
	{
		get;
		set;
	}

	/// <summary>
	/// Жильци квартиры
	/// </summary>
	private Person * people
	{
		get;
		set;
	}

	/// <summary>
	/// Количество жильцов в квартире
	/// </summary>
	private int n_person
	{
		get;
		set;
	}

	/// <summary>
	/// Сколько жильцов добавлено через метод AddPerson
	/// </summary>
	private int size
	{
		get;
		set;
	}

	public virtual IEnumerable<Person> Person
	{
		get;
		set;
	}

	public virtual void AddPerson(Person p)
	{
		throw new System.NotImplementedException();
	}

	public Apartment()
	{
	}

	public Apartment(int n)
	{
	}

	public ~Apartment()
	{
	}

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	public Apartment(const Apartment& orig)
	{
	}

	public virtual void show()
	{
		throw new System.NotImplementedException();
	}

	public virtual Apartment operator=(const Apartment & orig)
	{
		throw new System.NotImplementedException();
	}

}

