import type { Metadata } from "next";
import { Outfit } from "next/font/google"; // Modern, geometric font fitting Neo-Japan theme
import "./globals.css";

const outfit = Outfit({
	subsets: ["latin"],
	variable: "--font-outfit",
	display: "swap",
});

export const metadata: Metadata = {
	title: "Devspace 2026",
	description: "Neo-Japan / Cyberpunk Hackathon",
};

export default function RootLayout({
	children,
}: Readonly<{
	children: React.ReactNode;
}>) {
	return (
		<html lang="en">
			<body className={`${outfit.variable} font-sans antialiased bg-black text-white`}>
				{children}
			</body>
		</html>
	);
}
