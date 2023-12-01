[% USE Koha %]
[% IF ( relatives_issues_count ) %]
 <table id="relatives-issues-table" style="width: 100% !Important;">
 <thead>
 <tr>
 <th scope="col">Due date (unformatted, hidden)</th>
 <th scope="col">Ngày hết hạn</th>
 <th scope="col">Nhan đề</th>
 <th scope="col">Record-level item type</th>
 <th scope="col">Kiểu tài liệu</th>
 <th scope="col">Bộ sưu tập</th>
 <th scope="col">Kho tài liệu</th>
 <th scope="col">Checked out on (hidden, unformatted)</th>
 <th scope="col">Ngày ghi mượn</th>
 <th scope="col">Nơi ghi mượn</th>
 <th scope="col">Ký hiệu phân loại</th>
 <th scope="col">Số bản sao</th>
 <th scope="col">Phí</th>
 <th scope="col">Tiền phạt</th>
 <th scope="col">Giá tiền</th>
 <th scope="col">Bạn đọc</th>
 </tr>
 </thead>
 </table>
[% END %]
