from django.test import TestCase
from .models import NewsReport
from datetime import date
from django.utils.timezone import now


class TestNewsArticles(TestCase):
    def test_news_report_basic(self):
        report = NewsReport.objects.create(
            publish_date=now().date(),
            headline="Bray win the FAI Cup",
            details="Jayo scored and the cup came home",
            category="club",
        )
        self.assertEqual(str(report), "Bray win the FAI Cup")
        # There is a race condition in this test.   Running at midnight
        # may lead to failures.
        self.assertEqual(report.publish_date, date.today())
        self.assertEqual(report.expire, None)

    def test_check_default_date(self):
        report = NewsReport.objects.create(
            headline="Bray win the FAI Cup",
            details="Jayo scored and the cup came home",
            category="club",
        )
        self.assertEqual(report.publish_date, date.today())

    def test_check_expiry_date(self):
        report = NewsReport.objects.create(
            publish_date=date.today(),
            headline="Bray win the FAI Cup",
            details="Jayo scored and the cup came home",
            category="club",
        )
        self.assertEqual(report.expire, None)
        report.expire = date(2020, 3, 1)
        self.assertEqual(report.expire, date(2020, 3, 1))
