package main;

import java.io.Serializable;

@SuppressWarnings("serial")
public class Factura implements Serializable {
	private int numar;
	private int sumaTotala;

	public Factura(int numar, int sumaTotala) {
		this.numar = numar;
		this.sumaTotala = sumaTotala;
	}

	public int getNumar() {
		return numar;
	}

	public void setNumar(int numar) {
		this.numar = numar;
	}

	public int getSumaTotala() {
		return sumaTotala;
	}

	public void setSumaTotala(int sumaTotala) {
		this.sumaTotala = sumaTotala;
	}

	@Override
	public String toString() {
		return "Factura [numar=" + numar + ", sumaTotala=" + sumaTotala + "]";
	}

}
