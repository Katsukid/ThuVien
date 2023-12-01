<option value="relevance">Sắp xếp kết quả tìm theo</option>
<optgroup label="Tần suất sử dụng">
 [% IF ( sort_by == "popularity_dsc" ) %]
 <option value="popularity_dsc" selected="selected">Tần suất sử dụng (Nhiều - Ít)</option>
 [% ELSE %]
 <option value="popularity_dsc">Tần suất sử dụng (Nhiều - Ít)</option>
 [% END %]
 [% IF ( sort_by == "popularity_asc" ) %]
 <option value="popularity_asc" selected="selected">Tần suất sử dụng (Ít - Nhiều )</option>
 [% ELSE %]
 <option value="popularity_asc">Tần suất sử dụng (Ít - Nhiều )</option>
 [% END %]
</optgroup>
<optgroup label="Tác giả">
 [% IF ( sort_by == "author_az" || sort_by == "author_asc" ) %]
 <option value="author_az" selected="selected">Tác giả (A-Z)</option>
 [% ELSE %]
 <option value="author_az">Tác giả (A-Z)</option>
 [% END %]
 [% IF ( sort_by == "author_za" || sort_by == "author_dsc" ) %]
 <option value="author_za" selected="selected">Tác giả (Z-A)</option>
 [% ELSE %]
 <option value="author_za">Tác giả (Z-A)</option>
 [% END %]
</optgroup>
<optgroup label="Ký hiệu phân loại">
 [% IF ( sort_by == "call_number_asc" ) %]
 <option value="call_number_asc" selected="selected">Ký hiệu phân loại (0-9 tới A-Z)</option>
 [% ELSE %]
 <option value="call_number_asc">Ký hiệu phân loại (0-9 tới A-Z)</option>
 [% END %]
 [% IF ( sort_by == "call_number_dsc" ) %]
 <option value="call_number_dsc" selected="selected">Ký hiệu phân loại (Z-A tới 9-0)</option>
 [% ELSE %]
 <option value="call_number_dsc">Ký hiệu phân loại (Z-A tới 9-0)</option>
 [% END %]
</optgroup>
<optgroup label="Ngày liên quan">
 [% IF ( sort_by == "pubdate_dsc" ) %]
 <option value="pubdate_dsc" selected="selected">Năm xuất bản/Phát hành: Mới nhất - Cũ nhất</option>
 [% ELSE %]
 <option value="pubdate_dsc">Năm xuất bản/Phát hành: Mới nhất - Cũ nhất</option>
 [% END %]
 [% IF ( sort_by == "pubdate_asc" ) %]
 <option value="pubdate_asc" selected="selected">Năm xuất bản/Phát hành: Cũ nhất - Mới nhất</option>
 [% ELSE %]
 <option value="pubdate_asc">Năm xuất bản/Phát hành: Cũ nhất - Mới nhất</option>
 [% END %]
 [% IF ( sort_by == "acqdate_dsc" ) %]
 <option value="acqdate_dsc" selected="selected">Ngày bổ sung: Mới nhất - Cũ nhất</option>
 [% ELSE %]
 <option value="acqdate_dsc">Ngày bổ sung: Mới nhất - Cũ nhất</option>
 [% END %]
 [% IF ( sort_by == "acqdate_asc" ) %]
 <option value="acqdate_asc" selected="selected">Ngày bổ sung: Cũ nhất - Mới nhất</option>
 [% ELSE %]
 <option value="acqdate_asc">Ngày bổ sung: Cũ nhất - Mới nhất</option>
 [% END %]
</optgroup>
<optgroup label="Nhan đề">
 [% IF ( sort_by == "title_az" || sort_by == "title_asc" ) %]
 <option value="title_az" selected="selected">Nhan đề (A-Z)</option>
 [% ELSE %]
 <option value="title_az">Nhan đề (A-Z)</option>
 [% END %]
 [% IF ( sort_by == "title_za" || sort_by == "title_dsc" ) %]
 <option value="title_za" selected="selected">Nhan đề (Z-A)</option>
 [% ELSE %]
 <option value="title_za">Nhan đề (Z-A)</option>
 [% END %]
</optgroup>
