import csv
import unittest
from pathlib import Path

CSV_PATH = Path(__file__).resolve().parents[1] / "examples" / "sample_readings.csv"


class SampleReadingsTests(unittest.TestCase):
    def test_csv_has_expected_columns_and_illustrative_rows(self):
        with CSV_PATH.open(newline="", encoding="utf-8") as handle:
            rows = list(csv.DictReader(handle))

        self.assertGreater(len(rows), 0)
        self.assertEqual(
            set(rows[0].keys()),
            {"timestamp", "temperature_c", "humidity_percent", "record_type"},
        )
        self.assertTrue(all(row["record_type"] == "illustrative" for row in rows))

    def test_numeric_values_are_parseable_and_plausible(self):
        with CSV_PATH.open(newline="", encoding="utf-8") as handle:
            rows = list(csv.DictReader(handle))

        for row in rows:
            temperature = float(row["temperature_c"])
            humidity = float(row["humidity_percent"])
            self.assertGreaterEqual(temperature, -40.0)
            self.assertLessEqual(temperature, 125.0)
            self.assertGreaterEqual(humidity, 0.0)
            self.assertLessEqual(humidity, 100.0)


if __name__ == "__main__":
    unittest.main()
